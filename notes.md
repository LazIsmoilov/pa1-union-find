# Union-Find notes

## The problem
Track a partition of n elements into disjoint sets, supporting:
- find(x): which set is x in? (root of its tree)
- union(x, y): merge x and y's sets

Naive version: each element points to a parent, find() walks up to the root.
Without any optimization, a bad sequence of unions can build a tree that's
basically a linked list — find() degrades to O(n).

## Two optimizations
1. Union by rank: when merging two trees, attach the shorter one under the
   root of the taller one. Keeps tree height ~log n instead of letting it
   grow unbounded.
2. Path compression: every time find() walks up to a root, point every
   node on that path directly at the root. Future finds on those nodes
   are O(1).

Together these give near-constant amortized time per op (inverse-Ackermann,
practically a constant for any n you'd ever see).

## Hand trace — naive, worst case
Union(1,2), Union(2,3), Union(3,4), Union(4,5) always attaching the new
element under the existing root:

1 -> 2 -> 3 -> 4 -> 5   (chain, height 4)

find(1) now walks 4 hops. Do this for n elements, find() is O(n).

## Hand trace — path compression + union by rank
Same sequence, but union by rank keeps things flat:

    2
   /|\
  1 3 4
      |
      5   (roughly, depending on tie-breaking)

find(5) walks up, and path compression re-points 5 (and everything it
passed through) straight at the root. Second find(5) is O(1).

## What I'm building
- naive_union_find.hpp — no compression, no rank
- union_find.hpp — path compression + union by rank
- benchmark.cpp — build MSTs via Kruskal's on random graphs of increasing
  size, measure total time spent in union-find calls for each variant
- Hypothesis before running anything: the naive version should be
  roughly linear-per-op (or worse on adversarial chains), the optimized
  version should look flat/near-constant as n grows. Writing this down
  now so I can check it against what actually happens.