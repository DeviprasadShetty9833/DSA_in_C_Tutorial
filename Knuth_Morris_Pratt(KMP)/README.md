# Knuth-Morris-Pratt

String:
| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 |
|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|
| b | a | b | a | b | a | b | a | b | c | a | b | a | b | c | a | b | a | b |

Pattern:: 
| a | b | a | b | c | a | b | a | b |
|--|--|--|--|--|--|--|--|--|

Step 1: Prepare Longest Prefix Suffix (LPS) table 

| Index | 0 |  1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|--|--|--|--|--|--|--|--|--|--|
| Pattern | a | b | a | b | c | a | b | a | b |
| LPS | 0 | 0 | 1 | 2 | 0 | 1 | 3 | 1 | 4 |

- At Index 0, `a` appears for 1st time in prefix, len of LPS[1] = 0
- At Index 1, `a` ≠ `b` → no common prefix-suffix. len of LPS[2] = 0
- At Index 2, Pattern starts with `a` & ends with `a`, len of LPS[3] = 1
- At Index 3, `ab` appears for 2nd time in prefix, len of LPS[4] = 2
- At Index 4, `c` appears for 1st time in prefix, len of LPS[5] = 0
- At Index 5, `a` appears for 3rd time in prefix, len of LPS[6] = 1
- At Index 6, Starts with `aba` & Ends with `aba`, len of LPS[7] = 3
- At Index 7, `ab` appears for 4th time in prefix, len of LPS[8] = 4
- At Index 8, `a` appears for 1st time in prefix, len of LPS[1] = 0


