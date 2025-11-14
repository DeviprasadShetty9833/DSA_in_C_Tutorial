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
Pointer | ⌈m/2⌉ | m |
