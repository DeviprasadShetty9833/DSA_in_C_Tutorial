

📌 What is an AVL Tree?

· Self-balancing Binary Search Tree (BST)
· Named after inventors Adelson-Velsky and Landis
· Key Property: For every node, the height difference between left and right subtrees is at most 1
· This difference is called Balance Factor (BF)

---

🧮 Balance Factor (BF)

For any node:

Balance Factor = height(left subtree) - height(right subtree)

Valid values: -1, 0, 1

If |BF| > 1 → Tree is unbalanced → Rotation needed

---

🔄 Rotations in AVL Tree

4 Types of Rotations:

1. Left Rotation (LL Rotation)

· When node is right-heavy (BF = -2) and right child is right-heavy or balanced (BF = -1 or 0)
· Example: Insert 30 in: 10 → 20 → 30 (straight line right)

```
    10 (BF=-2)
      \
      20 (BF=-1)
        \
        30 (BF=0)
```

After Left Rotation on 10:

```
      20 (BF=0)
     /   \
    10    30
```

2. Right Rotation (RR Rotation)

· When node is left-heavy (BF = 2) and left child is left-heavy or balanced (BF = 1 or 0)
· Example: Insert 30 in: 50 → 40 → 30 (straight line left)

```
      50 (BF=2)
     /
    40 (BF=1)
   /
  30 (BF=0)
```

After Right Rotation on 50:

```
      40 (BF=0)
     /   \
    30    50
```

3. Left-Right Rotation (LR Rotation)

· When node is left-heavy (BF = 2) but left child is right-heavy (BF = -1)
· Two steps: Left rotate on child, then Right rotate on node
· Example: Insert 35 in: 50 → 30 → 40

```
      50 (BF=2)
     /
    30 (BF=-1)
      \
       40 (BF=0)
```

Step 1: Left rotate on 30

```
      50 (BF=2)
     /
    40 (BF=1)
   /
  30
```

Step 2: Right rotate on 50

```
      40 (BF=0)
     /   \
    30    50
```

4. Right-Left Rotation (RL Rotation)

· When node is right-heavy (BF = -2) but right child is left-heavy (BF = 1)
· Two steps: Right rotate on child, then Left rotate on node
· Example: Insert 35 in: 30 → 40 → 35

```
    30 (BF=-2)
      \
      40 (BF=1)
     /
    35
```

Step 1: Right rotate on 40

```
    30 (BF=-2)
      \
      35 (BF=-1)
        \
        40
```

Step 2: Left rotate on 30

```
      35 (BF=0)
     /   \
    30    40
```

---

📝 AVL Insertion Steps

1. Normal BST Insertion
2. Update heights from inserted node up to root
3. Check Balance Factor at each ancestor
4. If |BF| > 1 at any node:
   · Identify imbalance type (LL, RR, LR, RL)
   · Perform appropriate rotation
5. Continue upward until root

---

🎬 Complete Insertion Example

Insert sequence: 30, 20, 40, 10, 25, 5

Step 1: Insert 30

```
    30 (BF=0)
```

Step 2: Insert 20

```
      30 (BF=1)
     /
    20 (BF=0)
```

Step 3: Insert 40

```
      30 (BF=0)  ← Balanced
     /   \
    20    40
```

Step 4: Insert 10

```
      30 (BF=1)
     /   \
    20    40
   /
  10
```

Check BF: 20(BF=1), 30(BF=2) → Imbalance at 30
Type: LL (left-left) → Right Rotation on 30

```
      20 (BF=0)
     /   \
    10    30 (BF=0)
            \
             40
```

Step 5: Insert 25

```
      20 (BF=0)
     /   \
    10    30 (BF=-1)
         /   \
        25    40
```

All BFs: 25(0), 40(0), 30(-1), 10(0), 20(0) → Balanced

Step 6: Insert 5

```
      20 (BF=1)
     /   \
    10    30
   /     /  \
  5     25   40
```

Check BF: 10(BF=1), 20(BF=2) → Imbalance at 20
Type: LL (left-left) → Right Rotation on 20

```
      10 (BF=0)
     /   \
    5     20 (BF=0)
         /   \
        15    30
             /  \
            25   40
```

Wait! We inserted 5, not 15. Let me correct:

Actually after inserting 5:

```
      20 (BF=1)
     /   \
    10    30
   /     /  \
  5     25   40
```

BFs: 10(1), 20(2) → LL → Right rotate on 20

```
      10 (BF=-1)
     /   \
    5     20 (BF=0)
         /   \
        15?   30
```

Correction: There's no 15! Let's trace properly:

Initial after insert 5:

```
      20 (BF=1)
     /   \
    10    30 (BF=-1)
   /     /  \
  5     25   40
```

Check BF at 10: height(left)=1, height(right)=-1 → BF=1
Check BF at 20:height(left)=2, height(right)=2 → BF=0 actually!

Let me recalculate heights properly:

· Node 5: height=0, BF=0
· Node 25: height=0, BF=0
· Node 40: height=0, BF=0
· Node 10: height=1, BF=1 (left:5, right:null)
· Node 30: height=1, BF=0 (left:25, right:40)
· Node 20: height=2, BF=0 (left:10(1), right:30(1))

Actually tree is balanced! My mistake. Let's continue...

Final tree is balanced already with the given sequence.

---

📊 Complexity Analysis

Operation Time Complexity Space Complexity
Search O(log n) O(1) iterative, O(log n) recursive
Insert O(log n) O(log n) for recursion stack
Delete O(log n) O(log n)
Rotation O(1) O(1)

Why O(log n)?

· AVL tree maintains height ≈ 1.44 log₂(n)
· Maximum height difference ≤ 1 ensures near-perfect balance

---

🆚 AVL Tree vs Red-Black Tree

AVL Tree Red-Black Tree
Stricter balance ( BF
Faster lookups Slower lookups than AVL
More rotations during insert/delete Fewer rotations
Better for search-intensive apps Better for insert/delete-intensive apps
Examples: Databases where search > update Examples: Java TreeMap, C++ map

---

💡 Applications of AVL Trees

1. Database indexing (when frequent searches)
2. Memory management in OS
3. Dictionaries/Spell checkers
4. 3D graphics (scene graphs)
5. Router tables in networking

---

🧠 Viva Questions & Answers

Q1: Why AVL tree over BST?

A: BST can degenerate to O(n) in worst case (sorted insertion). AVL guarantees O(log n) by self-balancing.

Q2: Balance Factor calculation?

A: BF = height(left) - height(right). Height of null = -1, leaf = 0.

Q3: What's the maximum height difference between two leaves?

A: At most 1 (due to BF constraint at every node).

Q4: How many rotations needed for insertion?

A: At most 2 (for LR/RL cases) or 1 (for LL/RR).

Q5: Is AVL tree always perfectly balanced?

A: No, but height is bounded by ~1.44 log₂n vs perfect BST's log₂n.

Q6: Can we have all nodes with BF=0?

A: Only possible for perfect binary trees with 2ʰ-1 nodes.

Q7: Time complexity of deletion?

A: O(log n) but may require multiple rotations up to root.

Q8: Real-world usage example?

A: PostgreSQL uses AVL trees for indexing when data changes moderately but searches are frequent.

---

📝 Quick Revision Points

1. Self-balancing BST with |BF| ≤ 1
2. 4 rotations: LL(RR), RR(LL), LR, RL
3. Insert/Delete: O(log n) with possible rotations
4. Search: Faster than Red-Black but more rotations on update
5. Height: ≤ 1.44 log₂n
6. Used when search operations >> insert/delete

---

🎯 For Viva Tomorrow:

· Practice drawing rotation cases with 3-4 nodes
· Know how to calculate BF at each step
· Remember which rotation for which imbalance
· Compare with Red-Black trees (likely question) 

---
