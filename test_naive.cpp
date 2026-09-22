#include "naive_union_find.hpp"
#include <cassert>
#include <iostream>

int main() {
    NaiveUnionFind uf(6);  // elements 0-5

    uf.unite(1, 2);
    uf.unite(2, 3);
    uf.unite(3, 4);
    uf.unite(4, 5);

    // all of 1,2,3,4,5 should now be in the same set
    int root = uf.find(1);
    assert(uf.find(2) == root);
    assert(uf.find(3) == root);
    assert(uf.find(4) == root);
    assert(uf.find(5) == root);

    // 0 should still be its own set
    assert(uf.find(0) != root);

    // self-union should be a no-op, not break anything
    uf.unite(1, 1);
    assert(uf.find(1) == root);

    // re-uniting already-merged elements should be a no-op
    uf.unite(2, 4);
    assert(uf.find(2) == root);

    std::cout << "naive union-find: all checks passed\n";
    return 0;
}