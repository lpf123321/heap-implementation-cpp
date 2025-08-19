## Heap Definition?

A **heap** is a special kind of **binary tree–based data structure** that satisfies the **heap property**:

* In a **max heap**:
  Every parent node is **greater than or equal to** its children.
  (So the largest element is always at the root.)

* In a **min heap**:
  Every parent node is **less than or equal to** its children.
  (So the smallest element is always at the root.)

## Properties of a Heap

1. **Shape property**:
   A heap is always a **complete binary tree** → all levels are fully filled except possibly the last, which is filled left to right.

2. **Heap property**:
   Defined as above (parent ≥ children for max heap, parent ≤ children for min heap).

3. **Efficient access**:

   * In a max heap, you can always access the **largest element** in **O(1)** time.
   * In a min heap, you can always access the **smallest element** in **O(1)** time.


## Implementation

Although heaps are conceptually binary trees, they are usually implemented using **arrays** (not linked nodes):

* Root stored at index `0` (or `1` in some implementations).
* For a node at index `i`:

  * Left child → `2*i + 1`
  * Right child → `2*i + 2`
  * Parent → `(i - 1) // 2`


## Time Complexity

| Operation       | Complexity |
| --------------- | ---------- |
| Insert          | O(log n)   |
| Extract Min/Max | O(log n)   |
| Peek Min/Max    | O(1)       |
| Build Heap      | O(n)       |

## Applications

* **Priority Queues** (most common use — heaps are often used to implement them)
* **Heap Sort** (a sorting algorithm using heap property)
* **Graph algorithms** (like Dijkstra’s shortest path, Prim’s minimum spanning tree)
* **Scheduling problems** (task scheduling, event simulation)

**In summary:**
A **heap** is a complete binary tree that allows **fast access** to the smallest or largest element, and supports **efficient insertion and deletion**. That’s why it’s the backbone of **priority queues**.
