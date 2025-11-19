# B+ Tree

- A self-balancing search tree, and an extension of the B-Tree.
- Maintains sorted data and allows search, insert, delete in O(log n).

### Properties of B+ Tree

```
For a B+ Tree of order m:
- Internal nodes and leaf nodes have different structures.
- All data is stored only in the leaf nodes.
- Keys in internal nodes are replicated in the leaf nodes.
- All leaf nodes are linked together in a sequential linked list
- All leaves are at the same level.
```
```
Internal Nodes (Index Nodes):
- Store keys + pointers to child nodes.
- Each node has at most m children.
- Each node has at least ⌈m/2⌉ children (except root).
- Each node has at least ⌈m/2⌉ - 1 keys (except root).
- Each node has at most m-1 keys.
- Root can have minimum 2 children (if not leaf).
```
```
Leaf Nodes (Data Nodes):
- Store keys + data pointers + next leaf pointer
- Are linked together to form a sequential linked list.
- A leaf node can hold at most m-1 key-data pairs.
- A leaf node must have at least ⌈(m-1)/2⌉ key-data pairs. (Note:
  rules can vary)
```

| Node Type |	Element |	Min |	Max |
|--|--|--|--|
| Internal | Keys | ⌈m/2⌉ - 1	| m - 1 |
| Internal | Children	| ⌈m/2⌉	| m |
| Leaf | Key-Data Pairs	| ⌈(m-1)/2⌉	| m - 1|



Structure:

Internal Node (Index Node):
               | Bp | 20 | Bp | 50 | Bp |
                /          |         \
   (All < 20)     (>= 20 and < 50)   (>= 50)

Leaf Nodes (Data Nodes):
... -> | Bp | 10 | Dp | 15 | Dp | -> | Bp | 20 | Dp | 30 | Dp | -> ...
       [... Previous Leaf ...]      [... Next Leaf ...]



Bp → Block pointer → Points to another node (internal or leaf).

Key → Key value.

Dp → Data pointer → points to Data (exists only in leaf nodes).

Formula (Block Size):

Internal Node: nBp + (n-1)key <= Block size
Leaf Node:     (n*Key + n*Dp) + 1_NextLeafBp <= Block size



1. Searching

Search always proceeds from the root to a leaf node.

Internal node keys are "signposts" to guide the search.

Branching is inclusive: To find X in a node [ 30, 60 ]:

X < 30 → Go left.

X >= 30 and X < 60 → Go middle.

X >= 60 → Go right.

Even if you are searching for 30 and see it in an internal node, you must follow the pointer (>= 30) to the leaf to find the actual data.

2. Insertion

Steps:

- Search for the appropriate leaf node.
- Insert the key-data pair in sorted order.
- If the node overflows (keys > m-1):

  Split the node into two.
  COPY the *smallest key* from the new right node and
  promote it to the parent.
  Link the new leaf node to its sibling.

- If the parent (internal) node overflows:
  
  Split the internal node.
  MOVE (do not copy) the middle key to the parent.

- Repeat splitting upward if necessary.



Example:

Insert: 10, 20, 30, 40, 50
(Assuming m=3, Max Keys = 2)

Step 1: Insert 10

      [10|Dp]

Step 2: Insert 20

      [10|Dp, 20|Dp]

Step 3: Insert 30

      [10|Dp, 20|Dp, 30|Dp] → Overflow!

  Split: Left [10|Dp], Right [20|Dp, 30|Dp]
  Promote (copy) smallest key from right (20)

           [ 20 ]
          /      \
      [10|Dp] -> [20|Dp, 30|Dp]

Step 4: Insert 40

      Search: 40 >= 20, go right.
      Leaf: [20|Dp, 30|Dp, 40|Dp] → Overflow!

  Split: Left [20|Dp], Right [30|Dp, 40|Dp]
  Promote (copy) smallest key from right (30)

           [ 20, 30 ]
          /     |    \
      [10|Dp] [20|Dp] [30|Dp, 40|Dp]
      
      (Note: The leaf for 20 is now empty.
      A better split: Left[20,30] Right[40]. Let's
      follow a common ⌈n/2⌉ split)

Let's re-do Step 3 & 4 (splitting ⌈(m+1)/2⌉):

Step 3: Insert 30
      [10, 20, 30] -> Overflow!
      Split: Left [10, 20], Right [30]
      Promote smallest from right (30)

           [ 30 ]
          /      \
      [10, 20] -> [30]

Step 4: Insert 40
      Search: 40 >= 30, go right.

           [ 30 ]
          /      \
      [10, 20] -> [30, 40]

Step 5: Insert 50
      Search: 50 >= 30, go right.
      Leaf: [30, 40, 50] -> Overflow!
      Split: Left [30, 40], Right [50]
      Promote smallest from right (50)

           [ 30, 50 ]
          /     |    \
      [10, 20] -> [30, 40] -> [50]



3. Deletion

Steps:

- Locate the leaf node containing the key.
- Delete the key-data pair.
- If the key also exists in an internal node,
  it remains there (it's just a signpost).
- If node underflows (keys < min):

  1. Borrow (Redistribute) from an adjacent sibling.
     Move a key-data pair from sibling to the
     deficient node.
     UPDATE the parent's signpost key to reflect
     the new smallest key.

  2. If Borrow fails (siblings are at min), Merge.
     Merge the deficient node and its sibling.
     DELETE the separating key from the parent.

- If parent node underflows, repeat rebalancing upward.



Example:

Start Tree (from insertion example):
           [ 30, 50 ]
          /     |    \
      [10, 20] -> [30, 40] -> [50]
(Min keys = 1)

Step 1: Delete 20 (Simple, but causes underflow)

           [ 30, 50 ]
          /     |    \
        [10] -> [30, 40] -> [50]
    (Node [10] is in underflow!)

Step 2: Rebalance (Borrow)
    - Node [10] must borrow.
    - Right sibling [30, 40] has 2 keys (can spare one).

    Borrow Process:
    1. Move [30|Dp] from sibling to [10]. Node
       becomes [10, 30].
    2. Sibling becomes [40].
    3. UPDATE the parent signpost. The new
       smallest key in the right sibling is 40.
       The parent key [30] must become [40].

           [ 40, 50 ]   <-- Parent key updated
          /     |    \
      [10, 30] -> [40] -> [50]

Step 3: Delete 30 (from this new tree)
    
           [ 40, 50 ]
          /     |    \
        [10] -> [40] -> [50]
    (Node [10] is in underflow!)

Step 4: Rebalance (Merge)
    - Node [10] must rebalance.
    - Right sibling [40] is at minimum (1).
      Cannot borrow.
    - We must Merge.

    Merging Process:
    1. Merge [10] with its sibling [40].
    2. New merged node is [10, 40].
    3. DELETE the separating key [40] from
       the parent node.
    4. Parent [40, 50] becomes [50].

                      [ 50 ]
                     /      \
                 [10, 40] -> [50]

