// benchmark.cpp
#include "kruskal.hpp"
#include "graph_gen.hpp"
#include "union_find.hpp"
#include "naive_union_find.hpp"
#include <chrono>
#include <iostream>
#include <vector>

template <typename UnionFindType>
double timeKruskal(int n, const std::vector<Edge>& edges) {
    auto start = std::chrono::high_resolution_clock::now();
    kruskalMST<UnionFindType>(n, edges);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::milli>(end - start).count();
}

int main() {
    std::vector<int> sizes = {100, 500, 1000, 5000, 10000, 20000, 50000};
    const double density = 0.05;   // sparse-ish, keeps edge count manageable at large n
    const unsigned seed = 42;

    std::cout << "n,naive_ms,optimized_ms\n";

    for (int n : sizes) {
        auto edges = generateGraph(n, density, seed);

        // run each a few times and take the average to smooth out noise
        const int repeats = 5;
        double naiveTotal = 0, optTotal = 0;

        for (int r = 0; r < repeats; r++) {
            naiveTotal += timeKruskal<NaiveUnionFind>(n, edges);
            optTotal += timeKruskal<UnionFind>(n, edges);
        }

        std::cout << n << "," << (naiveTotal / repeats) << "," << (optTotal / repeats) << "\n";
    }

    return 0;
}