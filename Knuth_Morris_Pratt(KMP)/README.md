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

- At Index 1, `a` appears for 1st time in prefix, LPS[1] = 0
- At Index 2, `b` appears for 1st time in prefix, LPS[2] = 0
- At Index 3, `a` appears for 2nd time in prefix, LPS[3] = 1
- At Index 4, `ab` appears for 2nd time in prefix, LPS[4] = 2
- At Index 5, `c` appears for 1st time in prefix, LPS[5] = 0
- At Index 6, `a` appears for 3rd time in prefix, LPS[6] = 1
- At Index 7, Starts with `aba` & Ends with `aba`, len of LPS[7] = 3
- At Index 8, `ab` appears for 4th time in prefix, LPS[8] = 4


