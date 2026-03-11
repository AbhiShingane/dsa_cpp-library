#pragma once
#include <vector>

class DisjointSetUnion {

    std::vector<int> parent;
    std::vector<int> rank;

public:

    DisjointSetUnion(int n) {

        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++)
            parent[i] = i;
    }

    int find(int x) {

        if(parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int x, int y) {

        int rx = find(x);
        int ry = find(y);

        if(rx == ry) return;

        if(rank[rx] < rank[ry])
            parent[rx] = ry;

        else if(rank[ry] < rank[rx])
            parent[ry] = rx;

        else {
            parent[ry] = rx;
            rank[rx]++;
        }
    }
};