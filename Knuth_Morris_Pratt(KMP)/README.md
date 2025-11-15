# Knuth-Morris-Pratt

String(S):
| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 |
|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|--|
| b | a | b | a | b | a | b | a | b | c | a | b | a | b | c | a | b | a | b |

Pattern(P): 
| a | b | a | b | c | a | b | a | b |
|--|--|--|--|--|--|--|--|--|

Step 1: Prepare Longest Prefix Suffix (LPS) table 

| Index j | 0 |  1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|--|--|--|--|--|--|--|--|--|--|
| Pattern P[j] | a | b | a | b | c | a | b | a | b |
| LPS | 0 | 0 | 1 | 2 | 0 | 1 | 2 | 3 | 4 |

- At Index 0, `a` appears for 1st time in prefix, len of LPS[1] = 0
- At Index 1, `a` ≠  `b` → no common prefix-suffix, len of LPS[2] = 0
- At Index 2, Pattern starts with `a` & ends with `a`, len of LPS[3] = 1
- At Index 3, Pattern starts with `ab` & ends with `ab`, len of LPS[4] = 2
- At Index 4, `a` ≠  `c` → no common prefix-suffix, len of LPS[5] = 0
- At Index 5, Pattern starts with `a` & ends with `a`, len of LPS[6] = 1
- At Index 6, Pattern starts with `ab` & ends with `ab`, len of LPS[7] = 2
- At Index 7, Pattern starts with `aba` & ends with `aba`, len of LPS[7] = 3
- At Index 8, Pattern starts with `abab` & ends with `abab`, len of LPS[8] = 4


