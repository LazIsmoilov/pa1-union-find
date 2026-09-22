#include "union_find.hpp"
#include <cassert>
#include <iostream>

int main() {
    UnionFind uf(6);  // elements 0-5

    uf.unite(1, 2);
    uf.unite(2, 3);
    uf.unite(3, 4);
    uf.unite(4, 5);

    int root = uf.find(1);
    assert(uf.find(2) == root);
    assert(uf.find(3) == root);
    assert(uf.find(4) == root);
    assert(uf.find(5) == root);

    assert(uf.find(0) != root);

    // a repeated find should still be consistent after path compression
    assert(uf.find(1) == root);
    
    // self-union should be a no-op, not break anything
    uf.unite(1, 1);
    assert(uf.find(1) == root);

    // re-uniting already-merged elements should be a no-op
    uf.unite(2, 4);
    assert(uf.find(2) == root);
    
    std::cout << "path-compressed union-find: all checks passed\n";
    return 0;
}