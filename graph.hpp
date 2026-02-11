#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

template <typename T>
class node
{
public:
    T data;
    int key;
    vector<node<T> *> neighbors;

    node(T val, int k) : data(val), key(k), neighbors{} {}

    // Don't delete neighbors - graph will manage this
    ~node() = default;
};

template <typename T_GRAPH>
class GRAPH
{
public:
    GRAPH(bool isDirected) : numVertices(0), vertices{}, root(nullptr), isDirected(isDirected) {}
    ~GRAPH()
    {
        // Delete all vertices
        for (node<T_GRAPH> *vertex : vertices)
        {
            delete vertex;
        }
    }
    void addVertex(T_GRAPH data, int key)
    {
        node<T_GRAPH> *newNode = new node<T_GRAPH>(data, key);
        vertices.push_back(newNode);
        if (root == nullptr)
        {
            root = newNode;
        }
        numVertices++;
    }
    void addEdge(int fromKey, int toKey)
    {
        node<T_GRAPH> *fromNode = nullptr;
        node<T_GRAPH> *toNode = nullptr;
        // make sure that both nodes exist in the graph
        for (node<T_GRAPH> *v : vertices)
        {
            if (v->key == fromKey)
                fromNode = v;
            if (v->key == toKey)
                toNode = v;
        }

        if (fromNode && toNode)
        {
            if (!isDirected)
            {

                toNode->neighbors.push_back(fromNode);
            }
            // Add edge in both directions for undirected graph
            fromNode->neighbors.push_back(toNode);
        }
    }
    void TraverseDFS(void);
    void createGraphFromList(vector<pair<T_GRAPH, int>> verticesList, vector<pair<int, int>> edgesList);

private:
    int numVertices;
    bool isDirected;
    // vector of vertices which contains linked list of edges
    vector<node<T_GRAPH> *> vertices;
    node<T_GRAPH> *root;
    void TraverseDFS_AUX(node<T_GRAPH> *current, unordered_set<node<T_GRAPH> *> &visited);
};

template <typename T_GRAPH>
void GRAPH<T_GRAPH>::TraverseDFS_AUX(node<T_GRAPH> *current, unordered_set<node<T_GRAPH> *> &visited)
{
    if (current == nullptr || visited.count(current))
        return;

    visited.insert(current);
    cout << current->data << " ";

    for (node<T_GRAPH> *neighbor : current->neighbors)
    {
        TraverseDFS_AUX(neighbor, visited);
    }
}

template <typename T_GRAPH>
void GRAPH<T_GRAPH>::TraverseDFS(void)
{
    if (root == nullptr)
        return;

    unordered_set<node<T_GRAPH> *> visited;
    TraverseDFS_AUX(root, visited);
}

template <typename T_GRAPH>
void GRAPH<T_GRAPH>::createGraphFromList(vector<pair<T_GRAPH, int>> verticesList,
    vector<pair<int, int>> edgesList){
    for (const auto &vertex : verticesList)
    {
        addVertex(vertex.first, vertex.second);
    }
    for (const auto &edge : edgesList)
    {
        addEdge(edge.first, edge.second);
    }
    }

#endif // GRAPH_H