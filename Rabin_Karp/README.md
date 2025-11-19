### Analyze Time Complexity of Naive String Matching Algorithm and Rabin-Karp String Matching Algorithm for a scenario where both the algorithms have same time complexity.


Both algorithms become **equally slow** when **every substring of the text has the same hash value as the pattern** (in Rabin–Karp) and **every comparison must be done** (in both algorithms).

This happens in the **worst case** for both methods.

---

# ⭐ **Scenario Giving Equal Time Complexity**

### **Let:**

* Text **T = "aaaaaaaaaa....a"** (all characters same)
* Pattern **P = "aaaa...a"** (also all 'a')

In this case:

### ✔ Naive Algorithm

Every alignment partially matches → requires **m comparisons**, then shift → next m comparisons → repeat.

### ✔ Rabin-Karp

All substrings have the **same hash value**, so the algorithm performs **spurious hits** at every shift → must do full O(m) comparisons as verification.

Therefore:

Both perform **m comparisons at each of (n–m+1) shifts** → **same complexity**.

---

# 📌 **Time Complexity Comparison (in this scenario)**

| Algorithm             | Best Case        | Average Case | Worst Case (when same)                         |
| --------------------- | ---------------- | ------------ | ---------------------------------------------- |
| Naive String Matching | **O(n – m + 1)** | **O(nm)**    | **O(nm)**                                      |
| Rabin–Karp            | **O(n + m)**     | **O(n + m)** | **O(nm)** ← Hash collisions cause verification |

---

# 🎯 **Explanation of Why They Become Equal**

### ✔ Naive

At each shift, the pattern is compared character by character.
For repeated characters (like 'aaaaaa...'), partial matches happen repeatedly → full comparison needed.

### ✔ Rabin–Karp

Intended to be faster using hashing.
But if all substrings have **same rolling hash**, then **every shift produces a false positive**.
Hence pattern comparison (O(m)) happens at every shift.

Thus both algorithms degenerate to:

[
O((n - m + 1) \cdot m ) = O(nm)
]

---

# 📌 **Final Exam-Ready Answer (Short)**

**Both Naive and Rabin–Karp algorithms have the same time complexity O(nm) when the pattern and text consist of repeated characters (e.g., "aaaa…a"). In this case, every shift produces a partial match for the Naive algorithm, and for Rabin–Karp, every substring of the text has the same hash as the pattern, causing hash collisions. Each alignment requires a full m-character comparison, resulting in O((n – m + 1)·m) = O(nm) for both algorithms.**

---
