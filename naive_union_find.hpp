// naive_union_find.hpp
#pragma once
#include <vector>
#include <numeric>

class NaiveUnionFind {
public:
    explicit NaiveUnionFind(int n) : parent(n) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        // TODO: walk to root, no compression, no rank logic
        return -1;
    }

    void unite(int x, int y) {
        // TODO: attach one root under the other, no rank comparison
    }

private:
    std::vector<int> parent;
};