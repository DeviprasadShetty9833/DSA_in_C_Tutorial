# Knuth-Morris-Pratt

String:
| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 |
|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|
| b | a | b | a | b | a | b | a | b | c | a | b | a | b | c | a | b | a | b |

Pattern:: 
| a | b | a | b | c | a | b | a | b |
|--|--|--|--|--|--|--|--|--|

Step 1: Prepare Longest Prefix Suffix (LPS) table 

| Index | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|--|--|--|--|--|--|--|--|--|
| Pattern | a | b | a | b | c | a | b | a | b |
| LPS | 0 | 0 | 1 | 2 | 0 | 1 | 3 | 1 | 4 |
