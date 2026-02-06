#include <iostream>
#include "graph.hpp"
int main()
{
    GRAPH<int> myGraph(false); // Create an undirected graph

    // Add vertices
    myGraph.addVertex(1, 1);
    myGraph.addVertex(2, 2);
    myGraph.addVertex(3, 3);
    myGraph.addVertex(4, 4);
    myGraph.addVertex(5, 5);
    myGraph.addVertex(6,6);
    // Add edges
    myGraph.addEdge(1, 2);
    myGraph.addEdge(2, 3);
    myGraph.addEdge(3, 4);
    myGraph.addEdge(2,6);
    myGraph.addEdge(1,5);

    // Traverse the graph (DFS)
    myGraph.TraverseDFS();

    return 0;
}