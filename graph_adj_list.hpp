#pragma once
#include <vector>
#include <iostream>

class Graph {

    int V;
    std::vector<std::vector<int>> adj;

public:

    Graph(int v) {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void print() {

        for(int i=0;i<V;i++) {

            std::cout<<i<<": ";

            for(int v: adj[i])
                std::cout<<v<<" ";

            std::cout<<"\n";
        }
    }
};