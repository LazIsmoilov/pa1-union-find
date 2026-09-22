// union_find.hpp
#pragma once
#include <vector>
#include <numeric>

class UnionFind {
public:
    explicit UnionFind(int n) : parent(n), rank(n, 0) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        // TODO: walk to root, then path-compress every node on the way
        return -1;
    }

    void unite(int x, int y) {
        // TODO: find roots, attach shorter-rank tree under taller
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};