# Red-Black Tree

Self-balancing binary search tree

### 5 Properties:
```
- Color Property: Every node is either RED or BLACK
- Root Property: The root is always BLACK
- Leaf Property: All leaves (NIL nodes) are BLACK
- Red Property: No two consecutive RED nodes (RED node cannot have RED parent or RED children)
- Path Property: Every path from a node to its descendant NIL leaves contains the same number of BLACK nodes
```
- A Red-Black can also have only Black nodes.

### 1. Insertion
```
Rules for Insert operation:
1. If tree is empty, create new node as root node with color black
2. else create new node as leaf node with color Red.
3. If parent of new node is black then stop.
4. If parent of new node is red then check the color of parent's sibling of new node.
    a. If color is black or null then do suitable rotation and recolor
    b. If color is red, then recolor also check if parent's parent of new node is not root node, then recolor it and recheck.
```
