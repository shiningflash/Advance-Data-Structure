# Advance Data Structure

A reference collection of advanced data structures and competitive-programming techniques, with clean, self-contained implementations in **C++**, **Python**, and **C#**. Includes solved problems from online judges (mostly LightOJ) to demonstrate practical usage.

> Maintained as a personal study repo — feel free to read, fork, or adapt for your own learning.

## Contents

### Core data structures (C++)

| File | Topic |
| --- | --- |
| [`binary_indexed_tree.cpp`](binary_indexed_tree.cpp) | Binary Indexed Tree (Fenwick Tree) |
| [`segment_tree.cpp`](segment_tree.cpp) | Segment Tree (point update, range query) |
| [`lazy_propagation.cpp`](lazy_propagation.cpp) | Segment Tree with Lazy Propagation |
| [`sqrt_decomposition.cpp`](sqrt_decomposition.cpp) | Square Root Decomposition |
| [`DisjointSetUnit.cpp`](DisjointSetUnit.cpp) | Disjoint Set Union (Union–Find) |
| [`Binary_Search_Tree.cpp`](Binary_Search_Tree.cpp) | Binary Search Tree |
| [`radix_tree.cpp`](radix_tree.cpp) | Trie / Radix Tree |
| [`ordered_set.cpp`](ordered_set.cpp) | Ordered Set using GNU policy-based trees |
| [`min_heap.cpp`](min_heap.cpp) | Min-Heap |
| [`linked_list.cpp`](linked_list.cpp) | Singly Linked List |
| [`circular_linked_list.cpp`](circular_linked_list.cpp) | Circular Linked List |
| [`stack.cpp`](stack.cpp) | Stack |
| [`queue.cpp`](queue.cpp) | Queue |
| [`queue_using_stack.cpp`](queue_using_stack.cpp) / [`queue_using_1_stack.cpp`](queue_using_1_stack.cpp) | Queue implemented using stacks |

### Online judge solutions

Worked-out problems demonstrating each technique in a contest setting:

- **Segment Tree** — [`online judge solution of segment tree/`](online%20judge%20solution%20of%20segment%20tree) — LightOJ 1080, 1087, 1093, 1103
- **Segment Tree (advanced)** — [`complicated version of segment tree/`](complicated%20version%20of%20segment%20tree) — LightOJ 1348, max-sum, occurrence queries
- **Trie Tree** — [`online judge solution of trie tree/`](online%20judge%20solution%20of%20trie%20tree) — LightOJ 1114, 1129, 1224, 1269, dictionary prefix search
- **SQRT Decomposition** — [`online judge solution of sqrt_decomposition/`](online%20judge%20solution%20of%20sqrt_decomposition) — LightOJ 1082

### Python (`PYTHON/`)

Basic data-structure implementations plus a `problem_solving/` folder with common interview patterns:

- Stack, queue, priority queue, file I/O examples
- Sliding window, two pointers, binary search, custom comparator
- Top-K problems, word frequency, outlier detection
- Trie tree, graph DFS, valid-parentheses stack

### C# (`CSHARP/`)

.NET implementations of selected structures: Binary Search Tree, Segment Tree, Priority Queue, custom sorting and map exercises.

## Getting started

### C++

Most files are single-file programs you can compile directly:

```bash
g++ -std=c++17 -O2 segment_tree.cpp -o segment_tree
./segment_tree
```

> The `ordered_set.cpp` example uses GNU policy-based data structures (`<ext/pb_ds/...>`), which are available with **g++** but not with clang's libc++.

### Python

Python files target Python 3 and have no external dependencies:

```bash
python3 PYTHON/stack.py
python3 PYTHON/problem_solving/sliding_window.py
```

### C#

The C# folder is a .NET project (targets `net5.0`). From inside `CSHARP/`:

```bash
dotnet run
```

## Topics covered

`segment-tree` · `lazy-propagation` · `binary-indexed-tree` · `disjoint-set-union` ·
`sqrt-decomposition` · `trie-tree` · `ordered-set` · `binary-search-tree` ·
`heap` · `stack` · `queue` · `linked-list`

## Contributing

This is primarily a personal study repository, but corrections and clearer implementations are welcome — please open an issue or pull request.

## License & copyright

© Amirul Islam — Competitive Programmer

Licensed under the [MIT License](LICENSE).
