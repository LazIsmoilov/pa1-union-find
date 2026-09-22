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
    while (parent[x] != x) {
        x = parent[x];
    }
    return x;
    }

    void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) return;   // already in the same set
    parent[rootX] = rootY;        // no rank logic — just attach one root under the other
    }

private:
    std::vector<int> parent;
};