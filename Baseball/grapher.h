#ifndef GRAPHER_H
#define GRAPHER_H
#include <QVariant>
#include <algorithm>
#include <QQueue>
#include "manageDB.h"

/**
* @brief Enum for visited/unvisited vertices
*/
enum vertexTag
{
    VISITED_VERTEX,
    UNEXPLORED_VERTEX
};

/**
* @brief Enum for different Edge2 types
*/
enum edgeTag
{
    UNEXPLORED_EDGE,
    DISCOVERY_EDGE,
    CROSS_EDGE
};

/**
* @brief struct for edges
*/
struct Edge2
{
    /**
    * @brief starting vertex
    */
    QString start;

    /**
    * @brief ending vertex
    */
    QString end;

    /**
    * @brief distance between vertices
    */
    int weight;

    /**
    * @brief type of edge
    */
    edgeTag eTag;
};


/**
* @brief struct for vertices
*/
struct Vertex
{
    /**
    * @brief name of stadium
    */
    QString vertex;

    /**
    * @brief list of edges from current stadium
    */
    QList<Edge2> edges;

    /**
    * @brief vertex tag
    */
    vertexTag vTag;
};

class graphHELPER
{
public:
    /**
    * @brief adjacency matrix constructor
    */
    graphHELPER();

    /**
    * @brief loads graph from database
    *
    * takes information from database and
    * loads it into adjacency matrix
    *
    */
    void loadGraphFromDB();

    /**
    * @brief adds Edge2 to graph
    *
    * Adds Edge2 to graph with given
    * vertices and Edge2 weight
    *
    * @param vert1
    * @param vert2
    * @param weight
    */
    void addEdge(QString city1, QString city2, int weight);

    /**
    * @brief performs BFS
    *
    * Performs a BFS starting at passed in
    * starting node
    *
    * @param start
    */
    void breadthFirstSearch(QString start);

    /**
    * @brief assists breadthFirstSearch() function
    *
    * Assists breadthFirstSearch() function in
    * performing the BFS
    *
    * @param start
    */
    void breadthFirstHelper(QString start);

    /**
    * @brief gets location of current vertex
    *
    * Gets index location of current vertex
    *
    * @param vertex
    *
    * @returns index of current vertex
    */
    int getLocationOf(QString vertex);

    /**
    * @brief finds closest vertex
    *
    * Funds closest unvisted vertex to
    * current vertex
    *
    * @param vertex
    *
    * @returns closest vertex
    */
    Vertex findClosestVertex(Vertex vertex);

    /**
    * @brief gets weight between two vertices
    *
    * Gets weight between two vertices passed in
    * as parameters
    *
    * @param vertex1
    * @param vertex2
    *
    * @returns weight between two vertices
    */
    int getWeightBetween(Vertex vertex1, Vertex vertex2);

    /**
    * @brief gets number of all unvisited siblings
    *
    * Gets number of all unvisted siblings from
    * current vertex
    *
    * @param vertex
    *
    * @returns number of unvisited siblings
    */
    int unvisitedSiblings(Vertex vertex);

    /**
    * @brief prints graph
    *
    * prints out adjacency matrix
    *
    */
    void printGraph();

    /**
    * @brief gets route
    *
    * gets route from adjacency matrix
    *
    * @returns route
    */
    QList<QString> getRoute();

    /**
    * @brief gets distance
    *
    * gets distance from adjacency matrix
    *
    * @returns distacne
    */
    int getDistance();

    /**
    * @brief dijkstra algorithm for custom trip
    *
    * dijkstra algorithm for custom trip
    *
    * @param selectedTeams
    *
    * @returns list of ordered team names
    */
    QVector<QString> dijkstraAll(QVector<QString> selectedTeams);

    /**
    * @brief dijkstra algorithm for 1 to 1 trip
    *
    * dijkstra algorithm for 1 to 1 trip
    *
    * @param selectedTeams
    *
    * @returns list of ordered team names
    */
    QVector<QString> dijkstra1to1(QString start, QString end);

    /**
    * @brief dijkstra algorithm for ordered trip
    *
    * dijkstra algorithm for ordered trip
    *
    * @param selectedTeams
    *
    * @returns list of ordered team names
    */
    QVector<QString> dijkstraRecursive(QVector<QString> selectedTeams);

    /**
    * @brief finds minimum distance in set
    *
    * finds minimum distance in set
    *
    * @param dist[]
    * @param sptSet[]
    *
    * @returns minimum distance in set
    */
    int minDistance(int dist[], bool sptSet[]);

    /**
    * @brief prints path
    *
    * prints dijkstra path
    *
    * @param parent[]
    * @param j
    */
    void printPath(int parent[], int j);

    /**
    * @brief prints final solution
    *
    * prints final dijkstra solution
    *
    * @param parent[]
    * @param dist[]
    */
    void printSolution(int dist[], int parent[]);

    /**
    * @brief prints final 1 to 1 solution
    *
    * prints final 1 to 1 dijkstra solution
    *
    * @param parent[]
    * @param dist[]
    * @param start
    * @param end
    */
    void print1to1(int dist[], int parent[], QString start, QString end);

    /**
    * @brief converts team to stadium
    *
    * converts team name to stadium name
    *
    * @param teamName
    *
    * @returns stadium name
    */
    QString teamToStadium(QString teamName);

    /**
    * @brief converts stadium to team
    *
    * converts stadium name to team name
    *
    * @param stadiumName
    *
    * @returns team name
    */
    QString stadiumToTeam(QString stadiumName);

    /**
    * @brief performs MST
    *
    * performs MST using prims algorithm
    *
    */
    void primMST();

    /**
    * @brief prints MST
    *
    * prints final MST route
    *
    * @param parent[]
    */
    void printMST(int parent[]);

    /**
    * @brief gets distance vector
    *
    * gets distance vector
    *
    * @returns vector of team names
    */
    QVector<QString> getNonDistanceVector();

private:
    /**
    * @brief number of vertices
    */
    int vertexCount;

    /**
    * @brief number of edges
    */
    int edgeCount;

    /**
    * @brief adjacency matrix
    */
    int** adjMatrix;

    /**
    * @brief list of vertices
    */
    Vertex* vertices;

    /**
    * @brief total distance traveled
    */
    int travelDistance;

    /**
    * @brief string to hold route
    */
    QString route;

    /**
    * @brief start vertex's index
    */
    int startIndex;

    /**
    * @brief end vertex's index
    */
    int endIndex;

    /**
    * @brief default Edge2 weight
    */
    int infinity = 99999;

    /**
    * @brief list of adjacency matrix route
    */
    QList<QString> routeAM;

    /**
    * @brief vector for dijkstra route
    */
    QVector<QString> dijkstraRoute;

    /**
    * @brief vector to hold distances
    */
    QVector<QString> nonDistanceVector;
};


#endif
