#pragma once
#include <vector>

class FenwickTree {

    std::vector<int> bit;
    int n;

public:

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n+1,0);
    }

    void update(int index, int value) {

        for(; index<=n; index += index & -index)
            bit[index] += value;
    }

    int query(int index) {

        int sum = 0;

        for(; index>0; index -= index & -index)
            sum += bit[index];

        return sum;
    }
};