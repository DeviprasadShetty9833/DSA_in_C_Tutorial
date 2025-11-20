Steps:
```
1. Initialize all vertices as unvisited
2. Choose any vertex as the start node and mark it visited
3. Insert all edges from this start node into a min-priority queue (min-heap)

4. While priority queue is NOT empty:
      a. Extract the edge with minimum weight
      b. If the edge connects to an unvisited vertex:
             – Add the edge to the MST
             – Mark the new vertex as visited
             – Insert all edges from this new vertex into the priority queue

5. Stop when MST contains (V – 1) edges
```
