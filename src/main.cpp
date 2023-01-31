#include <iostream>

#include "SimpleGraph.h"

int main(int, char**) 
{
    SimpleGraph<int> graph;

    // 0
    // |--> 1 <-> 2
    //      |     ^
    //      |     | 
    //      |---> 3
    //      v     |  
    // |--> 4 <---|
    // |--> 5

    auto v0 = graph.addVertice(0);
    auto v1 = graph.addVertice(1);
    auto v2 = graph.addVertice(2);
    auto v3 = graph.addVertice(3);
    auto v4 = graph.addVertice(4);
    auto v5 = graph.addVertice(5);

    graph.addEdge(v0, v1);
    graph.addEdge(v0, v4);
    graph.addEdge(v0, v5);
    
    graph.addEdge(v1, v3);
    graph.addEdge(v1, v4);
    
    graph.addEdge(v2, v1);

    graph.addEdge(v3, v2);
    graph.addEdge(v3, v4);

    std::cout << "DFS result:\n\t";
    graph.dfs([](auto node) {
        std::cout << node << " ";
    });
    std::cout << "\n";

    std::cout << "\nBFS result:\n\t";
    graph.bfs([](auto node) {
        std::cout << node << " ";
    });
    std::cout << "\n";

    return EXIT_SUCCESS;
}
