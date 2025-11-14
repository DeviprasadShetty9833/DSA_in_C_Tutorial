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
Key | ⌈m/2⌉ - 1 | m-1 |
Children | ⌈m/2⌉ | m |

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

*Example:*
```html
Insert: 10, 20, 30, 40, 50

Maximum keys per node: 2
Minimum keys per node (except root): 1
Maximum children: 3
Minimum children (except root): 2

Step 1:

  [10]

Step 2:

  [10, 20]

Step 3:

  [10, 20, 30] → Overflow!   (3 keys > m-1 = 2)

Split: [20] becomes root
      /    \
   [10]    [30]

Step 4:

         [20] 
        /    \
     [10]    [30, 40]

Step 5:

         [20] 
        /    \
     [10]    [30, 40, 50] → Overflow!

Split: [20, 40] becomes root
       /   |   \
     [10] [30] [50]


```



3. Deletion
