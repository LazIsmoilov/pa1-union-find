// kruskal.hpp
#pragma once
#include <vector>
#include <algorithm>
#include "graph_gen.hpp"

// Runs Kruskal's MST using whichever union-find type is passed in.
// Returns total weight of the MST (the actual tree isn't needed for
// benchmarking — we just care about correctness + time spent in UF ops).
template <typename UnionFindType>
long long kruskalMST(int n, std::vector<Edge> edges) {
    std::sort(edges.begin(), edges.end(),
              [](const Edge& a, const Edge& b) { return a.weight < b.weight; });

    UnionFindType uf(n);
    long long totalWeight = 0;
    int edgesUsed = 0;

    for (const auto& e : edges) {
        if (uf.find(e.u) != uf.find(e.v)) {
            uf.unite(e.u, e.v);
            totalWeight += e.weight;
            edgesUsed++;
            if (edgesUsed == n - 1) break;  // MST complete
        }
    }

    return totalWeight;
}