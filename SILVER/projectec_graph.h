/*

Header file for graph library.

*/
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <climits>


using namespace std;

/* graph<T>
 ******************************************************************************
 * Purpose: A template class representing a directed graph.
 ******************************************************************************/
template <typename T>
class graph {
    public:
    // Store the verticies in vector format
    vector<T> V;

    // Store the edges in pair-wise format
    vector<pair<T,T>> E;

    // Keep a table that converts from vertex labels to
    // computer-friendly numbers.
    map<T, int> toNum;

    // n x n matrix to keep a quick computer-friendly representation
    // of the edges.
    vector<vector<bool>> adj;

    /* graph(set<T> V, vector<pair<T,T>> E)
     *************************************************************************
     * Purpose: Initialize a directed graph with the given set of vertices and
     *          edges.
     *************************************************************************
     * Parameters:
     *  - set<T> V : A set of vertices representing the nodes in the graph.
     * 
     *  - vector<pair<T,T>> E : A vector of pairs representing the edges in the
     *                       graph, where each pair (u, v) indicates a directed
     *                       edge from vertex u to vertex v.
     *************************************************************************/
    graph(set<T> V, vector<pair<T,T>> E);

    /* graph(set<T> V)
     **************************************************************************
     * Purpose: Initialize a directed graph with a given set of vertices.
     **************************************************************************
     * Parameters:
     *  - set<T> V : A set of vertices to be included in the graph.
     **************************************************************************/
    graph(set<T> V);
    /* graphAsMap()
     **************************************************************************
     * Purpose: Convert the adjacency matrix representation of the graph to a
     *          map representation.
     **************************************************************************
     * Parameters:
     *  - None
     **************************************************************************/
    map<T, vector<T>> graphAsMap();

    /* graphAsAdjMatrix()
     **************************************************************************
     * Purpose: Retrieve the adjacency matrix representation of the directed 
     *          graph.
     **************************************************************************
     * Parameters:
     *  - None
     **************************************************************************/
    vector<vector<bool>> graphAsAdjMatrix();

    /* graphAsAdjList()
     **************************************************************************
     * Purpose: Convert the list of edges representation of the directed graph 
     *          to an adjacency list representation.
     **************************************************************************
     * Parameters:
     *  - None
     **************************************************************************/
    vector<vector<T>> graphAsAdjList();
};

/* graph<T>
 ******************************************************************************
 * Purpose: A template class representing a directed weighted graph.
 ******************************************************************************/
template <typename T>
class weighted_graph: public graph<T> {
    public:
    // Adjacency matrix storing weights.
    vector<vector<int>> W;

    weighted_graph(set<T> V, vector<pair<T,T>> E, vector<vector<int>> W);
    
    /* weighted_graph(set<T> V, vector<pair<pair<T,T>, int>> W)
     **************************************************************************
     * Purpose: Initialize a weighted directed graph with a set of vertices and
     *          weighted edges.
     **************************************************************************
     * Parameters:
     *  - set<T> V : A set containing the vertices of the graph
     * 
     *  - vector<pair<pair<T,T>, int>> W : A vector of pairs representing the
     *                                     weighted edges of the graph. Each
     *                                     pair consists of two vertices and an
     *                                     integer weight.
     **************************************************************************/
    weighted_graph(set<T> V, vector<pair<pair<T,T>, int>> W);
};


/* allGraphs()
 **************************************************************************
 * Purpose: Generate all possible undirected graphs with n vertices.
 **************************************************************************
 * Parameters:
 *  - int n : The number of vertices in the graphs to be generated.
 **************************************************************************/
vector<graph<int>> allGraphs(int n);

/* template<typename T>
 * map<T,int> dijkstra(weighted_graph<T> g, T startVertex)
 **************************************************************************
 * Purpose: Find the shortest path distances from a given start vertex to
 *          all other vertices in a weighted graph using Dijkstra's 
 *          algorithm.
 **************************************************************************
 * Parameters:
 *  - weighted_graph<T> g : The weighted graph to perform Dijkstra's 
 *                          algorithm on.
 * 
 *  - T startVertex : The starting vertex for the algorithm.
 **************************************************************************/
template<typename T>
map<T,int> dijkstra(weighted_graph<T> g, T startVertex);

#include "projectec_graph.hpp"