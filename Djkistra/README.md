Djkistra Algorithm

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
