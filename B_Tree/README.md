# B-Tree 

- A self-balancing search tree.
- Maintains sorted data and allows search, insert, delete in O(log n).

Properties of B-Tree
```html
For a B-tree of order m:
- Each node has at most m children
- Each node has at least ⌈m/2⌉ children (except root)
- Each node has at least ⌈m/2⌉ - 1 keys (except root)
- All leaves at same level
- Keys in node are sorted
- Root can have minimum 2 children (if not leaf)
-
```

|  | min | max |
|--|--|--|
| Key | ⌈m/2⌉ - 1 | m-1 |
| Children | ⌈m/2⌉ | m |

*Structure:*
```
             | Bp | 20 | Dp | Bp | 50 | Dp | Bp |
              /                \
| Bp | 10 | Dp | Bp |         | Bp | 30 | Dp | Bp |
```

- Bp →  Block pointer → Points to other node
- Key →  Key value
- Dp →  Data pointer →  points to Data

*Formula:*
```html
nBp + (n-1)key +(n - 1) Dp <= Block size
```

1. Searching

2. Insertion

*Steps:*
```html
- Search for appropriate leaf node
- Insert key in sorted order
- If node overflows (keys > m-1):

  Split node into two
  Median key moves to parent
  Left half and right half become children

- If parent overflows, repeat splitting upward
- Tree grows in height from top
```

*Example:*
```html
Insert: 10, 20, 30, 40, 50

Minimum keys per node (except root): 1
Maximum keys per node: 2
Minimum children (except root): 2
Maximum children: 3

Step 1: Insert 10

      [10]

Step 2: Insert 20

      [10, 20]

Step 3: Insert 30

      [10, 20, 30] → Overflow!   (3 keys > m-1 = 2)

  Split:     [ 20 ] becomes root
             /    \
          [10]    [30]

Step 4: Insert 40

             [ 20 ] 
             /    \
          [10]    [30,40]

Step 5: Insert 50

             [ 20 ] 
             /    \
          [10]    [30,40,50] → Overflow!

  Split:     [ 20, 40 ] becomes root
              /   |   \
            [10] [30] [50]


```

3. Deletion

*Steps:*
```html
- Locate key to delete
- If node has more than Min no. of key, then Delete
- else either Borrow from right or left
- if not possible to delete or borrow as no. of keys will be less, then Merge
```

*Example:*
```html
1]                    [ 30, 60 ]
                     /    |    \
            [10,20,25] [40,50] [70,80,90]

|          | min | max |
| Key      |  2  |  4  |
| Children |  3  |  5  |

Step 1: Delete 25 (Simple Delete)

                  [ 30, 60 ]
                  /    |    \
            [10,20] [40,50] [70,80,90]

Step 2: Delete 40 (Right Borrow)

                   [ 30, 60 ]
                  /    |    \
             [10,20] [50] [70,80,90]

  Borrowing Process:
    1. Borrow from right sibling [70, 80, 90]
    2. Smallest key from right sibling (70) moves to parent
    3. Parent's key (60) moves down 

                    [ 30, 70 ]  <-- Parent key updated
                   /    |    \
             [10,20] [50,60] [80,90]

Step 3: Delete 50 (Merge)

                   [ 30, 70 ] 
                  /    |    \
             [10,20] [60] [80,90] 

  Borrow from left / right sibling not possible as both have min no. keys i.e 2 keys.

  Merging Process:
    1. Take the deficient node [60].
    2. Take its left sibling [10, 20].
    3. Pull down the parent key that separates them (30).
    4. Combine all three into a single new node: [10, 20, 30, 60].
    5. The parent node [30, 60] loses the 30 key and its child pointer.

                          [ 70 ]
                         /    \
               [10,20,30,60] [80,90]   
```

```html
2]                                  [ 50 ]
                                  /        \
                      [ 20, 30 ]             [ 70, 80 ]
                    /     |     \           /     |     \
               [10,15] [25,28] [35,38] [60,65] [75,78] [90,95]

|          | min | max |
| Key      |  2  |  4  |
| Children |  3  |  5  |

Step 1: Delete 10 (Cascading effect)

                                    [ 50 ]
                                  /        \
                      [ 20, 30 ]             [ 70, 80 ]
                    /     |     \           /     |     \
                  [15] [25,28] [35,38] [60,65] [75,78] [90,95]

  Borrow from right sibling not possible as it has min no. keys i.e 2 keys.

  Merging Process:
    1. Take the deficient node [15].
    2. Take its right sibling [25,28].
    3. Pull down the parent key that separates them (20).
    4. Combine all three into a single new node: [15,20,25,28].
    5. The parent node [20, 30] loses the 20 key and its child pointer.

                                [ 50 ]
                              /         \
                      [ 30 ]              [ 70, 80 ]
                    /        \            /    |    \
               [15,20,25,28] [35,38] [60,65] [75,78] [90,95]

  Borrow from right sibling not possible as it has min no. keys i.e 2 keys.

  Merging Process:
    1. Take the deficient node [30].
    2. Take its right sibling [70,80].
    3. Pull down the parent key that separates them (50).
    4. Combine all three into a single new node: [30,50,70,80].
    5. The parent node [50] loses the 50 key and its child pointer.


                                 [ 30, 50, 70, 80 ]
                             /    /      |      \    \
                [15,20,25,28] [35,38] [60,65] [75,78] [90,95]
```
