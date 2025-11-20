Djkistra Algorithm

  ⏺️ Dijkstra’s Algorithm is a greedy graph search method used to find the shortest path from a single source to all other nodes in a graph.

  ⏺️ At each step, it selects the nearest unvisited node from the source.

  ⏺️ It records the shortest distance to each node and the previous node for reconstructing the path.

 🟠 Key Points:
 - Works for both directed and undirected graphs.
 - All edge weights must be non-negative.


- Finds shortest path from source node to all other nodes
- Greedy algorithm - makes locally optimal choices
- Works only with non-negative edge weights

Steps:
1. Start from source node (distance = 0)
2. All other nodes: distance = infinity
3. Repeat until all nodes visited:
   a. Pick the unvisited node with smallest distance
   b. Update its neighbors: 
        new distance = current distance + edge weight
        if new distance < old distance, update
   c. Mark current node as visited
