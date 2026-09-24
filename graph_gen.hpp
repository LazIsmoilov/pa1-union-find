// graph_gen.hpp
#pragma once
#include <vector>
#include <random>
#include <algorithm>

struct Edge {
    int u, v;
    int weight;
};

// Generates a random connected graph on n vertices.
// Guarantees connectivity by first building a random spanning tree,
// then adding extra random edges up to the requested density.
inline std::vector<Edge> generateGraph(int n, double density, unsigned seed) {
    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> weightDist(1, 1000);

    std::vector<Edge> edges;

    // Step 1: random spanning tree to guarantee connectivity.
    // Shuffle vertices, connect each to a random earlier one.
    std::vector<int> order(n);
    for (int i = 0; i < n; i++) order[i] = i;
    std::shuffle(order.begin(), order.end(), rng);

    for (int i = 1; i < n; i++) {
        std::uniform_int_distribution<int> pick(0, i - 1);
        int j = pick(rng);
        edges.push_back({order[i], order[j], weightDist(rng)});
    }

    // Step 2: add extra random edges until we hit the target density.
    long long maxEdges = static_cast<long long>(n) * (n - 1) / 2;
    long long targetEdges = static_cast<long long>(maxEdges * density);
    std::uniform_int_distribution<int> vertexDist(0, n - 1);

    while (static_cast<long long>(edges.size()) < targetEdges) {
        int u = vertexDist(rng);
        int v = vertexDist(rng);
        if (u != v) {
            edges.push_back({u, v, weightDist(rng)});
        }
    }

    return edges;
}