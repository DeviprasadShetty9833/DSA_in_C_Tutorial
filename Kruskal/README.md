Steps:
```
1. Create a forest (each vertex is its own set)
2. Make a list of all edges
3. Sort edges in INCREASING order of weight

4. For each edge (u, v) in sorted order:
       a. Find the set of u (Find(u))
       b. Find the set of v (Find(v))
       c. If Find(u) ≠ Find(v):      // No cycle formed
             – Add (u, v) to the MST
             – Union(u, v)

5. Stop when MST contains (V – 1) edges
```
