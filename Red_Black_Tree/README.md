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
    b. If color is red, then recolor parent and uncle also check if grandparent(parent's parent) of new node is not root node, then recolor grandparent and recheck.
```

Case 4a: Uncle is BLACK



Case 4b: Uncle is RED, Recolor parent, uncle, and grandparent
```
      Black(G)              Red(G)
      /    \               /    \
   Red(P) Red(U)  →    Black(P) Black(U)
    /                   /
 Red(N)              Red(N)
```

```
Step 1: Insert 10 (Root)

    10(B)   ...(Rule 1)
    
Step 2: Insert 18

    10(B)
      \
      18(R)    ...(Rule 2) ← No violation (parent is BLACK)

Step 3: Insert 7

    10(B)
    /    \
  7(R)   18(R)   ...(Rule 2) ← No violation (both children RED, but parent BLACK)    

Step 4: Insert 15

    10(B)
    /    \
  7(R)   18(R)
         /
       15(R)    ...(Rule 4b) ← Violation! RED parent (18) and RED child (15)

    Recolor: 7(R), 18(R) → 7(B), 18(B)

        10(B)
        /    \
      7(B)   18(B)
             /
           15(R)

Step 5: Insert 16

    10(B)
    /    \
  7(B)   18(B)
         /
       15(R)
         \
         16(R)   ...(Rule 4a) ← Violation! RED parent (15) and RED child (16)

    1) LR Rotation → LL Rotation, then recolor

         18(B)        18(B)
         /            /
       15(R)   →    16(R)    →   16(B)
         \         /            /    \
         16(R)   15(R)        15(R)  18(R)

     10(B)
    /    \
  7(B)   16(B)
        /    \
      15(R)  18(R)

Step 6: Insert 30

     10(B)
    /    \
  7(B)   16(B)
        /    \
      15(R)  18(R)
                 \
                 30(R)    ...(Rule 4b) ← Violation! RED parent (18) and RED child (30)

    Recolor: 15(R), 18(R) → 15(B), 18(B) and 16(B) → 16(R) as 16 is not a root node.


     10(B)
    /    \
  7(B)   16(R)
        /    \
      15(B)  18(B)
                 \
                 30(R)  

Step 7: Insert 25

     10(B)
    /    \
  7(B)   16(R)
        /    \
      15(B)  18(B)
                 \
                 30(R)  
                    \
                    25(R)   ...(Rule 4a) ← Violation! RED parent (30) and RED child (25)

    1) RR Rotation, then recolor

         18(B)        
            \           
            30(R)     →     25(B)
                \          /    \
                25(R)    18(R)  30(R)

     10(B)
    /    \
  7(B)   16(R)
        /    \
      15(B)  25(B)
            /    \
          18(R)  30(R)

Step 8: Insert 40

     10(B)
    /    \
  7(B)   16(R)
        /    \
      15(B)  25(B)
            /    \
          18(R)  30(R)
                    \
                     40(R)    ...(Rule 4b) ← Violation! RED parent (30) and RED child (25)

    Recolor: 18(R), 30(R) → 18(B), 30(B) and 25(B) → 25(R) as 25 is not a root node.

     10(B)
    /    \
  7(B)   16(R)
        /    \
      15(B)  25(R)     ...(Rule 4a) ← Violation! RED parent (16) and RED child (25)
            /    \
          18(B)  30(B)
                    \
                     40(R)

    1) RR Rotation, then recolor

         10(B)        
            \           
            16(R)     →     16(B)
                \          /    \
                25(R)    10(R)  30(R)


              16(B)
           /        \
      10(R)          25(R)
     /     \        /    \
  7(B)    15(B)  18(B)    30(B)
                              \
                              40(R)
 

```
