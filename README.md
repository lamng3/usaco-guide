# usaco-guide
farmer john 👨‍🌾 sharing a fuji 🍎 with bessie the cow 🐄

## Modular Inverse
In modular arithmetic, "dividing by 2" is not the same as "integer-dividing by 2". 

This is because a modular residue `r = R (mod M)` carries no guarantee that `r` is even (even if `R` was); and the integer division `r/2` will truncate or give the wrong result whenever `r` is odd (or if `R` "wrapped around" more than once modulo `M`).

The only guaranteed way to compute `R/2 (mod M)` from `r = R (mod M)` is to multiple by the modular inverse of 2, which is `R/2 (mod M) = r x 2^{-1} (mod M)`. 

Since `M = 1_000_000_007` is prime, `2^{-1} = 500_000_004 (mod M)`. A more generalized way to calculate division of any number in modular setting is `inv(x) = pow(x, mod-2, mod)`.

### See More

[Errichto](https://codeforces.com/profile/Errichto) shared a very useful and generalized video on [Computations Modulo P in Competitive Programming](https://youtu.be/-OPohCQqi_E?si=rTvnfOQR-EzMqAFH).

CP-Algorithms: [Modular Multiplicative Inverse](https://cp-algorithms.com/algebra/module-inverse.html)

USACO Guide: [Modular Arithmetic](https://usaco.guide/gold/modular?lang=cpp#modular-inverse).

### Exercise
* [CSES Two Sets II](https://cses.fi/problemset/task/1093/)

## Fenwick Tree

A Fenwick tree can support the following range operations:

- Point Update and Range Query
- Range Update and Point Query
- Range Update and Range Query

In some cases, we need to perform [Coordinate Compression]() to avoid MLE (memory limit exceeded). MLE happens quite often with large array values limit but small array size limit.

### See More

CP-Algorithms: [Fenwick Tree](https://cp-algorithms.com/data_structures/fenwick.html)

### Exercise

* [List Removals](https://cses.fi/problemset/task/1749/): This is basically an OST implementation, requiring an observation at first about the ranks.

## Order Statistic Tree

OST is a variant of BST that supports:
- `rank(x)`: count number of elements < x
- `select(k)`: find the kth smallest element

Both operations can be performed in `O(log n)` worst case time when a self-balancing tree is used as the base data structure.

To turn a regular search tree into an order statistic tree, the nodes of the tree need to store one additional value, which is the size of the subtree rooted at that node.

Binary Jumping is used on BIT tree array, as each node at index `i` can have `i*2` and `i*2+1` as children nodes.

Obviously, the statement of [Inversion Counting](https://www.geeksforgeeks.org/dsa/inversion-count-in-array-using-merge-sort/) problem is quite simple. Yet, it takes some study to tackle it.

### See More

GFG: [Order statistic tree using fenwick tree (BIT)](https://www.geeksforgeeks.org/dsa/order-statistic-tree-using-fenwick-tree-bit/)

GFG: [Inversion Counting](https://www.geeksforgeeks.org/dsa/inversion-count-in-array-using-merge-sort/)

USACO: [Binary Jumping](https://usaco.guide/plat/binary-jump?lang=cpp)