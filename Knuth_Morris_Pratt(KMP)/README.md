# Knuth-Morris-Pratt

String:
| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 |
|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|
| a | b | a | b | c | a | b | c | a | b | a | b | a | b | d |

Pattern:: 
| a | b | a | b | d |
|--|--|--|--|--|

Step 1: Prepare Longest Prefix Suffix (LPS) table 

| Index | 1 | 2 | 3 | 4 | 5 |
|--|--|--|--|--|--|
| Pattern | a | b | a | b | d |
| LPS | 0 | 0 | 1 | 2 | 0 |
