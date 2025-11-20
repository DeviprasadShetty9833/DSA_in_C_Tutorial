Steps:
```
1. Start from source node (distance = 0)
2. All other nodes: distance = infinity  
3. Repeat (number of nodes - 1) times:
   For every edge (u→v):
        if distance[u] + weight < distance[v]:
            distance[v] = distance[u] + weight
4. Check for negative cycles by doing one more pass
```
