#ifndef GRAPHHELPER_H
#define GRAPHHELPER_H

#include <QVector>
#include <algorithm>
using namespace std;

// forward declaration
template <typename T>
struct Vertex;

//!
//! \brief Edge struct
//! Edge containing a starting point,
//! ending point, weight, and a starting and ending vertex
//!
template <typename T>
struct Edge
{
    T start;
    T end;
    double weight;
    Vertex<T>* endVertex;
    Vertex<T>* startVertex;
};

//!
//! \brief Vertex struct
//! Vertex containing data,
//! edges of the vertex, parent,
//! id, starting time, ending time,
//! and depth
//!
template <typename T>
struct Vertex
{
    // attributes of a vertex
    T value;
    int id;
    int startTime = -1;
    int endTime = -1;
    int depth;
    QVector<Edge<T>> edges;
    Vertex<T>* parent;
};

//!
//! \brief The clusterSets struct
//! Contains the parent, rank, and size of a set
//! Functions include creating set, finding set,
//! and merging sets
//!
struct clusterSets
{
    int *parent;
    int *rank;
    int size;

    //!
    //! \brief DisjointSets
    //! Creates a new parent and rank of size n + 1
    //! sets rank to 0 and parent from 0 to n
    //! \param size - size of the set
    //!
    clusterSets(int size)
    {
        // sets the size to parameter value and creates a parent and rank of size n + 1
        this->size = size;
        parent = new int[size + 1];
        rank = new int[size + 1];

        // assigns rank to 0 and parent to the value of i
        for (int i = 0; i <= size; i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    //!
    //! \brief findSet
    //! Finds the parent of the parameter u
    //! \param u - represents the element in which the parent is being searched
    //! \return - parent of paremeter u
    //!
    int findSet(int u)
    {
        // checks if u is not the parent
        if (u != parent[u])
        {
             // recursively calls the find function
             parent[u] = findSet(parent[u]);
        }
        // returns the parent value
        return parent[u];
    }

    //!
    //! \brief mergeSet
    //! finds x and y, and compares their ranks
    //! and merges accordingly
    //! \param x - represents the first set
    //! \param y - represents the second set
    //!
    void mergeSets(int x, int y)
    {
        // finds the parent value for x and y
        x = findSet(x);
        y = findSet(y);

        // compares the rank of x and y
        if (rank[x] > rank[y])
        {
            // sets parent of y to x
             parent[y] = x;
        }

        // sets the parent of x to y
        else
        {
            parent[x] = y;
        }

        // checks if the ranks of x and y are equal. Increments rank of y
        if (rank[x] == rank[y])
        {
            rank[y]++;
        }
    }
};

//!
//! \brief compareWeight struct
//! Compares the weight of the starting and ending edges
//! Sorts the edges in ascending order
//!
template <typename T>
struct compareWeight
{
    //!
    //! \brief operator ()
    //! \param start - value of type Edge. Starting edge
    //! \param end - value of type Edge. Ending edge
    //! \return true if the starting weight is less than or equal to the ending weight
    //! Returns false otherwise.
    //!
    bool operator()(const Edge<T>& start, const Edge<T>& end) const
    {
        // Returns false if the end edge weight is less than the weight of the start edge weight
        if (end.weight < start.weight)
        {
            return false;
        }

        // Returns true if weight of starting edge is less than weight of ending edge
        if (start.weight < end.weight)
        {
            return true;
        }

        // Returns true if both weights are equal
        return true;
    }
};

//!
//! \brief graphHelper class
//! Provides the definition of a graph which is then used to
//! implement the DFS, BFS, and MST of the graph. The edges and
//! total distance of the DFS, BFS, and MST is then displayed
//!
template <typename T>
class graphHelper
{
private:
    // number of vertices, edges, adj matrix, vertices of graph, and id's
    int vNum;
    int eNum;
    int** adjMat;
    Vertex<T>* vertices;
    QVector<pair<double,pair<int, int>>> edges;

    //!
    //! \brief DFSDriver
    //! Performs the DFS algorithm
    //! \param start - represents the starting point for the DFS algorithm
    //! \param visited - a QVector initialized to false until each edge is visited
    //! \param discoveryEdges - represents all the edges being discovered in the DFS algorithm
    //! \param counter - represents the counter in terms of time
    //!
    void DFSDriver(T start, QVector<bool> &visited, QVector<Edge<T>>& discoveryEdges, int counter = 0);

public:
    //!
    //! \brief graphHelper
    //! Initializes a new graph
    //! \param elements - represents an array of type T
    //! \param size - represents the size of the elements array
    //!
    graphHelper(T elements[], int size);

    //!
    //! \brief ~graphHelper
    //! Destroys a graph that goes out of scope
    //!
    ~graphHelper();

    //!
    //! \brief addEdge
    //! Adds edges to a graph
    //! \param start
    //! \param end
    //! \param weight
    //!
    void addEdge(T start, T end, double weight);

    //!
    //! \brief DFS
    //! \param start - represents the starting point to begin DFS
    //! \return QVector of edges which represents all the discovery edges
    //! from the DFS algorithm
    //!
    QVector<Edge<T>> DFS(T start);

    //!
    //! \brief BFS
    //! \param start - represents the starting point to begin BFS
    //! \return QVector of edges representing all the discovery edges
    //! from the BFS algorithm
    //!
    QVector<Edge<T>> BFS(T start);

    //!
    //! \brief kruskalMST
    //! Finds the MST of the baseball stadiums using
    //! Kruskal's Algorithm
    //! \return QVector of edges which are the edges
    //! of the MST.
    //!
    QVector<Edge<T>> kruskalMST();
};

/*************************************************************************
* graphHelper(T elements[], int size)
* -----------------------------------------------------------------------
* This constructor initializes a graph with vertices being assigned to the
* elements array and the adjacency matrix being assigned to 0
************************************************************************/
template <typename T>
graphHelper<T>::graphHelper(T elements[], int size)
{
    // sets number of vertices, vertices array, and adjacency matrix
    this->vNum = size;
    vertices = new Vertex<T>[size];
    adjMat = new int*[vNum];

    // sets the rows of the adjacency matrix, and the value and id for the vertices
    for (int row = 0; row < vNum; row++)
    {
        adjMat[row] = new int[vNum];
        vertices[row].value = elements[row];
        vertices[row].id = row;

        // sets the rows and columns of the adjacency matrix to 0
        for (int column = 0; column < vNum; column++)
        {
            adjMat[row][column] = 0;
        }
    }
}

/*************************************************************************
* ~graphHelper()
* -----------------------------------------------------------------------
* This destructor destroys any graph that goes out of scope
************************************************************************/
template<typename T>
graphHelper<T>::~graphHelper()
{
    // deletes the elements in the matrix
    for (int i = 0; i < vNum; i++)
    {
        delete [] adjMat[i];
    }

    // deletes the vertices
    delete [] vertices;

    // sets vertices and edges to 0
    vNum = 0;
    eNum = 0;
}

/*************************************************************************
* void addEdge(T start, T end, double weight)
* -----------------------------------------------------------------------
* This function adds an edge to the graph and initializes attributes of the
* vertices and edges
************************************************************************/
template <typename T>
void graphHelper<T>::addEdge(T start, T end, double weight)
{
    int first = 0;
    int last = 0;

    // checks if start or end is a vertex. Assigns i to
    for (int i = 0; i < vNum; i++)
    {
        if (start == vertices[i].value)
        {
            first = i;
        }
        if (end == vertices[i].value)
        {
            last = i;
        }
    }
    // Sets the edges to 1
    adjMat[first][last] = 1;

    // forward edge
    Edge<T> edgeForward = {start, end, weight};

    // pushes the forward edges to the vertices pushes the edge weight, start, and end ID
    vertices[first].edges.push_back(edgeForward);
    edges.push_back(make_pair( weight, make_pair(first, last)));

    // ending and starting vertex
    vertices[first].edges.back().endVertex = &vertices[last];
    vertices[first].edges.back().startVertex = &vertices[first];
}

/*************************************************************************
* QVector<Edge<T>> DFS(T start)
* -----------------------------------------------------------------------
* This function returns a QVector of discovery edges after calling the
* DFSDriver function
************************************************************************/
template<typename T>
QVector<Edge<T>> graphHelper<T>::DFS(T start)
{
    // set start and end time to -1 to compare edges
    for (int i = 0; i < vNum; i++)
    {
        vertices->startTime = -1;
        vertices->endTime = -1;
    }

    // sets the visited QVector to false initially and declares a QVector for the discovery edges
    QVector<bool> visited(vNum, false);
    QVector<Edge<T>> discoveryEdges;

    // calls the DFS function to get the discoverEdges
    DFSDriver(start, visited, discoveryEdges);

    // returns a QVector containing the discovery edges of the DFS performed
    return discoveryEdges;
}

/*************************************************************************
* void DFSDriver(T start, QVector<bool> &visited, QVector<Edge<T>>& discoveryEdges, int counter)
* -----------------------------------------------------------------------
* This recursive function performs a DFS traversal through all the baseball stadium graph
* starting from the vertex start. Keeps going until all vertices are visited
************************************************************************/
template<typename T>
void graphHelper<T>::DFSDriver(T start, QVector<bool> &visited, QVector<Edge<T>>& discoveryEdges, int counter)
{
    int totalDist = 0;
    int id = 0;

    // Sets the current vertex visited true and gets the id value
    for (int i = 0; i < vNum; i++)
    {
        if (vertices[i].value == start)
        {
            visited[i] = true;
            vertices[i].startTime = counter;
            id = i;
        }
    }

    // sort the edges of the vertex in ascending order by weight
    sort(vertices[id].edges.begin(), vertices[id].edges.end(), compareWeight<T>());

    // copies the edges
    QVector<Edge<T>> edges;
    for (auto it = vertices[id].edges.begin(); it != vertices[id].edges.end(); it++)
    {
        edges.push_back(*it);
    }

    // Traverses from 0 to size of edges
    for (int i = 0; i < edges.size(); i++)
    {
        // Checks if a vertex is not visited
        if (!visited[edges[i].endVertex->id])
        {
            // pushes the vertex to discovery edge
            discoveryEdges.push_back(edges[i]);

            // increments counter, gets the weight of the edge, and recursively calls the DFS function
            counter++;
            DFSDriver(edges[i].endVertex->value, visited, discoveryEdges, counter);
            counter++;
            edges[i].endVertex->endTime = counter;
            totalDist += edges[i].weight;
        }
    }
}

/*************************************************************************
* QVector<Edge<T>> BFS(T start)
* -----------------------------------------------------------------------
* This function performs a BFS traversal on a graph of baseball stadiums
* and returns the discovery edges until all vertices are visited
************************************************************************/
template <typename T>
QVector<Edge<T>> graphHelper<T>::BFS(T start)
{
    int totalDist = 0;
    QVector<Edge<T>> discoveryEdges;

    // QVector that checks whether a stadium has been visited
    QVector<bool> visited(vNum, false);
    QVector<int> stadiums;

    // location of QVector
    int currentStadium;

    // find starting index location
    int id = 0;
    for (int i = 0; i < vNum; i++)
    {
        if (start == vertices[i].value)
        {
            vertices[i].depth = 0;
            id = i;
        }
    }

    // pushes the id into the QVector
    stadiums.push_back(id);

    // Sets first id to true since it is the origin
    visited[id] = true;

    // keeps going until q is empty
    while (!stadiums.empty())
    {
        // assigns current to the value stored in stadiums
        currentStadium = stadiums[0];

        // gets id value
        for (int i = 0; i < vNum; i++)
        {
            if (vertices[currentStadium].value == vertices[i].value)
            {
                id = i;
            }
        }

        // sort the edges of the vertex in ascending order by edge weight
        sort(vertices[currentStadium].edges.begin(), vertices[currentStadium].edges.end(), compareWeight<T>());

        // erases the first iterator
        stadiums.erase(stadiums.begin());

        // Checks the adjacent vertices to the current vertex.
        for (int i = 0; i < vertices[currentStadium].edges.size(); i++)
        {
            // checks if Vertex has not been visited
            if (!visited[vertices[currentStadium].edges[i].endVertex->id])
            {
                // Push the adjacent vertex to the QVector
                stadiums.push_back(vertices[currentStadium].edges[i].endVertex->id);

                // Sets visited QVector to true
                visited[vertices[currentStadium].edges[i].endVertex->id] = true;

                // sets the parent vertex
                vertices[vertices[currentStadium].edges[i].endVertex->id].parent = &vertices[currentStadium];

                // increments the depth
                vertices[currentStadium].edges[i].endVertex->depth = vertices[currentStadium].depth + 1;

                // adds total distance and pushes into Discovery edges
                totalDist += vertices[currentStadium].edges[i].weight;
                discoveryEdges.push_back(vertices[currentStadium].edges[i]);
            }
        }
    }
    // returns the edges by BFS
    return discoveryEdges;
}

/*************************************************************************
* QVector<Edge<T>> kruskalMST()
* -----------------------------------------------------------------------
* This function performs a MST of the baseball stadiums using Kruskal's
* algorithm. A QVector containing the edges of the MST graph is returned
************************************************************************/
template<typename T>
QVector<Edge<T>> graphHelper<T>::kruskalMST()
{
    // discovery edges for the MST
    QVector<Edge<T>> discoveryEdges;
    double totalDist = 0;

    // sorts the edges by weight
    sort(edges.begin(), edges.end());

    // declares a set
    clusterSets disjoint(vNum);
    QVector<pair<double, pair<int, int>>>::iterator it;

    // traverses through the entire edges
    for (it = edges.begin(); it != edges.end(); it++)
    {
        // sets u to the first of second and v to the second of second
        int u = it->second.first;
        int v = it->second.second;

        // gets the set of u to the find of u and the set of v to the find of v
        int uSet = disjoint.findSet(u);
        int vSet = disjoint.findSet(v);

        // checks if the two sets are not equal
        if (uSet != vSet)
        {
            // Adds the edge to the discovery Edge since it is in the MST
            Edge<T> edge = {vertices[u].value, vertices[v].value, it->first};
            discoveryEdges.push_back(edge);

            // adds to the total Weight
            totalDist += it->first;

            // Merges the two sets
            disjoint.mergeSets(uSet, vSet);
        }
    }
    // returns a QVector of discoveryEdges of the MST
    return discoveryEdges;
}
#endif // GRAPHHELPER_H
