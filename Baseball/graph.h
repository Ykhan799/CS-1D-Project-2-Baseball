#ifndef GRAPH_H
#define GRAPH_H

#include <QMainWindow>
#include "manageDB.h"


namespace Ui {
class graph;
}

class graph : public QMainWindow
{
    Q_OBJECT

public:
    explicit graph(QWidget *parent = nullptr);
    ~graph();

    //!
    //! \brief displayGraph
    //! \param Edge - vector containing the edges and their weight
    //!
    void displayGraph(vector<Edge<QString>> Edge);

    //!
    //! \brief getGraph
    //! Creates a graph of size based on
    //! the number of stadiums. Adds the edges into the graph
    //! to be used for BFS, DFS, or MST
    //!
    void getGraph();


private slots:
    //!
    //! \brief on_back_clicked
    //! Allows the baseball fan or
    //! Administrator to go back to
    //! the home screen
    //!
    void on_back_clicked();

    //!
    //! \brief on_bfs_clicked
    //! Allows the baseball fan or admin
    //! to view the BFS of the baseball stadiums
    //! starting from Target Field
    //!
    void on_bfs_clicked();

    //!
    //! \brief on_dfs_clicked
    //! Allows the baseball fan or admin
    //! to view the DFS of the baseball stadiums
    //! starting from Oracle Park
    //!
    void on_dfs_clicked();

    //!
    //! \brief on_mst_clicked
    //! Allows the baseball fan or
    //! admin to view the MST of the baseball
    //! teams using Kruskal's Algorithm
    //!
    void on_mst_clicked();

private:
    Ui::graph *ui;
    graphHelper<QString>* createGraph;
    QString *stadium;
    manageDB* database;
};

#endif // GRAPH_H
