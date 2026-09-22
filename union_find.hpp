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
    if (parent[x] != x) {
        parent[x] = find(parent[x]);   // path compression: re-point x
                                        // directly at the root as we unwind
    }
    return parent[x];
    }

    void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) return;   // already in the same set

    // attach the shorter tree under the taller one
    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;   // same height — pick one as new root, height grows by 1
    }
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};