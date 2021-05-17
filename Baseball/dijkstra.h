#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <QString>

using namespace std;

/**
 * @brief The Edge struct
 */
struct Edge {

    /**
     * @brief u index of first node
     */
    int u;

    /**
     * @brief v index of second node
     */
    int v;

    int weight;
};

/**
 * @brief node
 * pair of int to represent node (weight, index)
 * Used for MST
 */
typedef pair<int, int> node;

/**
 * @brief Graph class based on directed adjacency matrix
 */
template <class Type>
class Graph
{
public:
    Graph();

    /**
     * @brief dfsOrder Order of nodes after DFS is run
     */
    vector<Type> dfsOrder;

    /**
     * @brief bfsOrder Order of nodes after BFS is run
     */
    vector<Type> bfsOrder;

    /**
     * @brief shortestOrder Visit all nodes in shortest order.
     * Populated by shortestPath()
     */
    vector<Type> shortestOrder;

    /**
     * @brief dijkstraOrder Order of nodes for multiDijkstra()
     */
    vector<Type> dijkstraOrder;

    /**
     * @brief Output edges in MST
     */
    QString mstString;

    /**
     * @brief Adds node to graph
     * @param obj Object to add to graph
     */
    void addNode(const Type obj);

    /**
     * @brief Add edge between two nodes
     * @param objU Name of first node
     * @param objV Name of second node
     * @param weight Weight of edge
     */
    void addEdge(const Type& objU, const Type& objV, int weight);

    /**
     * @brief Starts MST (Prim-Jarnik)
     * @return Total distance
     */
    int startMST();

    /**
     * @brief Starts DFS and populates dfsOrder
     * @param start Starting node
     * @return Total cost (distance)
     */
    int startDFS(const Type& start);

    /**
     * @brief Starts BFS and populates bfsOrder
     * @param start Starting node
     * @return Total cost (distance)
     */
    int startBFS(const Type& start);

    /**
     * @brief Start Dijkstra from starting point to destination
     * @param start Starting node
     * @param dest Destination
     * @return Total distance travelled
     */
    int startDijkstra(const Type& start, const Type& dest);

    /**
     * @brief Start recursive Dijkstra (visits all given nodes)
     * Saves path order to dijkstraOrder
     * @param nodes All nodes to visit
     * @param start Starting node
     * @return Total distance travelled
     */
    int startMultiDijkstra(vector<Type> nodes, const Type& start);

    vector<int> getMultiDijkstra(vector<Type> nodes, const Type& start);

    /**
     * @brief Finds shortest path to all nodes
     * Saves path in shortestOrder
     * @param start Starting node
     * @return Distance travelled
     */
    int startShortestPath(const Type& start);

private:

    /**
     * @brief size number of nodes
     */
    int size;

    /**
     * @brief List of data associated with index
     */
    vector<Type> nodeList;

    /**
     * @brief Adjacency matrix
     */
    vector<vector<Edge>> adjMatrix;

    /**
     * @brief Helper function to get index of node
     * @param obj Object to be found
     * @return Index of obj
     */
    int getIndex(const Type& obj);

    /**
     * @brief DFS recursive function
     * @param v Starting node index
     * @param visited Keeps track of each visited node
     * @return Total cost (distance)
     */
    int dfs(int v, vector<bool>& visited);

    /**
     * @brief Dijkstra pathfinding algorithm
     * @param start Name of starting node
     * @return Two dimentional array hold data for paths
     */
    vector<vector<int>> DijkstraPaths(const Type& start);

    /**
     * @brief Recursively runs Dijkstra over nodes
     * @param nodes List of nodes to visit
     * @param start Starting node
     * @return Total distance
     */
    int multiDijkstra(vector<Type> nodes, const Type& start);

    /**
     * @brief Finds shortest path from node to node
     * @param start Starting node
     * @return Total distance
     */
    int shortestPath(const Type& start);

    /**
     * @brief Compares Edges (sorts in increasing order)
     * @param a Edge a
     * @param b Edge b
     * @return true if Edge a is less than b
     */
    static bool compareWeight(const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    }
};

template<class Type>
Graph<Type>::Graph()
{
    size = 0;
}

template<class Type>
void Graph<Type>::addNode(Type obj) {
    nodeList.push_back(obj);
    size++;
    adjMatrix.resize(size);
    for (auto it = adjMatrix.begin(); it != adjMatrix.end(); it++)
        it->resize(size);
}

template<class Type>
void Graph<Type>::addEdge(const Type& objU, const Type& objV, int weight) {
    int u = getIndex(objU);
    int v = getIndex(objV);
    Edge uEdge = {u, v, weight};
    adjMatrix[u][v] = uEdge;
    //Edge vEdge = {v, u, weight};
    //adjMatrix[v][u] = vEdge;

}

template<class Type>
int Graph<Type>::getIndex(const Type& obj) {
    auto it = find(nodeList.begin(), nodeList.end(), obj);
    return it - nodeList.begin();
}

template<class Type>
int Graph<Type>::startDFS(const Type& start) {
    vector<bool> visited(size, false);
    dfsOrder.clear();

    return dfs(getIndex(start), visited);;
}

template<class Type>
int Graph<Type>::dfs(int v, vector<bool>& visited) {

    int distTraveled = 0;
    visited[v] = true;
    dfsOrder.push_back(nodeList[v]);

    // create adjacency list of valid nodes
    // and sort in order of increasing weight
    vector<Edge> adjList;
    for (auto it = adjMatrix[v].begin(); it != adjMatrix[v].end(); it++) {
        // find valid edge
        if (!visited[it->v] && it->weight > 0)
            adjList.push_back(*it);
    }
    sort(adjList.begin(), adjList.end(), compareWeight);

    for (auto it = adjList.begin(); it != adjList.end(); it++) {
        if (!visited[it->v]) {
            distTraveled += it->weight;
            distTraveled += dfs(it->v, visited);
        }
    }
    return distTraveled;
}

template<class Type>
int Graph<Type>::startBFS(const Type& start) {
    vector<bool> visited(size, false);
    queue<int> queue;
    int distTraveled = 0;

    int currNode = getIndex(start);
    queue.push(currNode);
    visited[currNode] = true;

    while (!queue.empty()) {
        currNode = queue.front();
        bfsOrder.push_back(nodeList[currNode]);
        queue.pop();

        // create adjacency list of valid edges
        vector<Edge> adjList;
        for (auto it = adjMatrix[currNode].begin();
             it != adjMatrix[currNode].end(); it++) {
            if (it->weight != 0 && !visited[it->v])
                adjList.push_back(*it);
        }
        sort(adjList.begin(), adjList.end(), compareWeight);

        for (auto it = adjList.begin(); it != adjList.end(); it++) {
            queue.push(it->v);
            visited[it->v] = true;
            distTraveled += it->weight;
        }
    }

    return distTraveled;
}

template<class Type>
int Graph<Type>::startMST() {

    priority_queue<node, vector<node>, greater<node>> pq;

    // starting node
    int src = 0;

    // parent of each node in MST
    vector<int> parent(size, -1);
    // distance to each node
    vector<int> distance(size, INT_MAX);
    vector<bool> inMST(size, false);

    // starting point
    pq.push(make_pair(0, src));
    distance[src] = 0;

    // temp adjacency list
    vector<Edge> adjList;

    while (!pq.empty()) {
        // look at first node in the priority queue
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        // get valid edges
        for (auto it = adjMatrix[u].begin(); it != adjMatrix[u].end(); it++) {
            if (it->weight > 0)
                adjList.push_back(*it);
        }

        // iterate through all adjacent vertices
        for (auto i = adjList.begin(); i != adjList.end(); i++)
        {
            int v = i->v;
            int dist = i->weight;

            // if v is valid and closer, push onto pq
            if (!inMST[v] && distance[v] > dist)
            {
                distance[v] = dist;
                pq.push(make_pair(distance[v], v));
                parent[v] = u;
            }
        }

        adjList.clear();
    }

    int weight;
    mstString = "";
    for (int i = 0; i < size; i++) {
        if (parent[i] != -1) {
            mstString += nodeList[parent[i]] + " - " + nodeList[i];
            weight = adjMatrix[parent[i]][i].weight;
            mstString += ": " + QString::number(weight);
            mstString += "\n";
        }
    }

    int total = 0;
    for (int dist : distance)
            total += dist;
    return total;
}

template<class Type>
int Graph<Type>::startDijkstra(const Type& start, const Type& dest) {
    vector<vector<int>> T;
    T = DijkstraPaths(start);
    return T[getIndex(dest)][1];
}

template<class Type>
int Graph<Type>::startMultiDijkstra(vector<Type> nodes, const Type& start) {
    dijkstraOrder.clear();
    return multiDijkstra(nodes, start);
}

template<class Type>
int Graph<Type>::multiDijkstra(vector<Type> nodes, const Type& start) {

    dijkstraOrder.push_back(start);

    // remove starting point from nodes
    auto pos = find(nodes.begin(), nodes.end(), start);
    if (pos != nodes.end())
        nodes.erase(pos);

    // base case
    if (nodes.size() < 1)
        return 0;

    vector<vector<int>> T;
    T = DijkstraPaths(start);

    // find closest in selected nodes
    int distance = INT_MAX;
    int closest = getIndex(start);
    int i = 0;
    for (Type node : nodes) {
        i = getIndex(node);
        if (T[i][1] < distance) {
            closest = i;
            distance = T[i][1];
        }
    }

    distance += multiDijkstra(nodes, nodeList[closest]);
    return distance;
}

template <typename Type>
vector<int> Graph<Type>::getMultiDijkstra(vector<Type> nodes, const Type& start)
{

    vector<int> getDist;

    dijkstraOrder.push_back(start);

    // remove starting point from nodes
    auto pos = find(nodes.begin(), nodes.end(), start);
    if (pos != nodes.end())
        nodes.erase(pos);

    // base case
    if (nodes.size() < 1)
    {
        getDist.push_back(0);
        return getDist;
    }

    vector<vector<int>> T;
    T = DijkstraPaths(start);

    // find closest in selected nodes
    int distance = INT_MAX;
    int closest = getIndex(start);
    int i = 0;
    for (Type node : nodes) {
        i = getIndex(node);
        if (T[i][1] < distance) {
            closest = i;
            distance = T[i][1];
            getDist.push_back(distance);
        }
    }

    return getDist;
}

template<class Type>
vector<vector<int>> Graph<Type>::DijkstraPaths(const Type& start) {
    vector<vector<int>> T(size);
    for (auto it = T.begin(); it != T.end(); it++)
        it->resize(3);

    for (unsigned int i = 0; i < nodeList.size(); i++) {
        T[i][0] = -1;       // parent node
        T[i][1] = INT_MAX;  // distance
        T[i][2] = 0;        // in SPT set (0=false, 1=true)
    }

    int startIndex = getIndex(start);
    T[startIndex][0] = startIndex;
    T[startIndex][1] = 0;
    T[startIndex][2] = 1;

    for (unsigned int i = 0; i < adjMatrix[startIndex].size(); i++) {
        T[adjMatrix[startIndex][i].v][0] = startIndex;
        T[adjMatrix[startIndex][i].v][1] = adjMatrix[startIndex][i].weight;
    }

    int shortestIndex = -1;
    int shortest = INT_MAX;
    for (int i = 0; i < (int)nodeList.size(); i++) {
        if (T[i][2] == 0){
            if (T[i][1] < shortest) {
                shortestIndex = i;
                shortest = T[i][1];
            }
        }
    }

    while (shortestIndex != -1) {
        for (unsigned int i = 0; i < adjMatrix[shortestIndex].size(); i++) {
            int current = adjMatrix[shortestIndex][i].v;

            if (T[current][2] == 0) {
                if ((T[shortestIndex][1] + adjMatrix[shortestIndex][i].weight) < T[current][1]) {
                    T[current][1] = T[shortestIndex][1] + adjMatrix[shortestIndex][i].weight;
                    T[current][0] = shortestIndex;
                }
            }
        }

        T[shortestIndex][2] = 1;

        shortestIndex = -1;
        shortest = INT_MAX;
        for (int i  = 0; i < (int)nodeList.size(); i++) {
            if (T[i][2] == 0){
                if (T[i][1] < shortest) {
                    shortestIndex = i;
                    shortest = T[i][1];
                }
            }
        }
    }

    return T;
}

template<class Type>
int Graph<Type>::startShortestPath(const Type& start) {
    shortestOrder.clear();
    return shortestPath(start);
}

template<class Type>
int Graph<Type>::shortestPath(const Type& start) {

    int curr = getIndex(start);
    int next = 0;
    vector<bool> visited(size, false);

    int distance = 0;
    int min;
    do {
        visited[curr] = true;
        shortestOrder.push_back(nodeList[curr]);
        min = INT_MAX;
        for (int j = 0; j < size; j++) {
            if (adjMatrix[curr][j].weight > 0 && !visited[j]
                    && adjMatrix[curr][j].weight < min) {
                next = j;
                min = adjMatrix[curr][next].weight;
            }
        }
        distance += adjMatrix[curr][next].weight;
        curr = next;
    } while(!visited[curr]);
    return distance;
}


// explicitly instantiate template so it's compiled
template class Graph<QString>;

#endif // GRAPH_H
