#pragma once
#include <vector>

class SegmentTree {

    std::vector<int> tree;
    int n;

    void build(std::vector<int>& arr, int node, int start, int end) {

        if (start == end)
            tree[node] = arr[start];

        else {

            int mid = (start + end) / 2;

            build(arr, 2*node, start, mid);
            build(arr, 2*node+1, mid+1, end);

            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }

public:

    SegmentTree(std::vector<int>& arr) {

        n = arr.size();
        tree.resize(4*n);

        build(arr,1,0,n-1);
    }
};