#include "kruskal.hpp"
#include "graph_gen.hpp"
#include "union_find.hpp"
#include "naive_union_find.hpp"
#include <cassert>
#include <iostream>

int main() {
    auto edges = generateGraph(20, 0.3, 42);

    long long w1 = kruskalMST<UnionFind>(20, edges);
    long long w2 = kruskalMST<NaiveUnionFind>(20, edges);

    assert(w1 == w2);  // same graph -> same MST weight, regardless of UF implementation

    std::cout << "MST weight (optimized UF): " << w1 << "\n";
    std::cout << "MST weight (naive UF):     " << w2 << "\n";
    std::cout << "Kruskal's cross-check: passed\n";

    return 0;
}