# Binomial Heap

- A Binomial Heap is a collection (forest) of Binomial Trees that supports efficient priority-queue operations (insert, extract-min, merge).

- It is designed so that **merging two heaps is very fast** (unlike binary heaps).

---

# 🔹 1. What is a Binomial Tree?

A **Binomial Tree Bₖ** (order k) is defined recursively:

* **B₀** = a single node
* **Bₖ** = two **Bₖ₋₁** trees combined such that:

  * One becomes the child of the other's root
  * Children are always attached **in left-to-right order**

### Height of Bₖ:

```
Height(Bₖ) = k
```

### Number of nodes:

```
Nodes(Bₖ) = 2ᵏ
```

### Children count:

Root of Bₖ has exactly **k children**.

---

# 🔹 2. Structure of a Binomial Heap

A **Binomial Heap H** is a set of **binomial trees** that satisfy:

### ✔ **Property 1 – Each tree is a binomial tree.**

### ✔ **Property 2 – No two trees have the same degree.**

(At most one B₀, one B₁, one B₂, …)

This is similar to how each digit appears only once in a binary number.

Hence, a heap containing *n* elements has **O(log n)** trees.

### ✔ **Property 3 – Each binomial tree satisfies min-heap property**

For every node:

```
key(parent) ≤ key(child)
```

So minimum element is always at one of the **roots**.

---

# 🔹 3. Why “Binomial”?

Because the **structure resembles the binomial expansion coefficients**
C(k,0), C(k,1), … C(k,k).

---

# 🔹 4. Example: Binomial Trees B₀, B₁, B₂

### **B₀ (order 0)**

A single node

```
• 
```

### **B₁ (order 1)**

2 nodes

```
  •
  |
  •
```

### **B₂ (order 2)**

4 nodes

```
     •
   / | \
  •  •  •
```

### **A Heap Example:**

H consists of trees: B₀, B₂, B₃
(no duplicate degrees)

---

# 🔹 5. Operations on a Binomial Heap

## **1️⃣ Insert(x)**

Equivalent to **merging the heap with a single-node heap**.

Steps:

1. Create a new binomial heap H' with just one B₀ node.
2. Union (merge) H and H'.

### Time Complexity:

```
O(log n)
```

---

## **2️⃣ Union / Merge Two Binomial Heaps**

This is the MOST important feature.

Steps:

1. Merge root lists of both heaps in **increasing order of degree**.
2. Combine trees of same degree just like binary addition:

   * If you have two Bₖ trees → link them to form Bₖ₊₁.
3. Ensure no two trees have same degree in the result.

### Time Complexity:

```
O(log n)
```

---

## **3️⃣ Find-Min()**

Minimum is the **smallest root** among all roots.

Time:

```
O(log n)        (scan root list)
```

---

## **4️⃣ Extract-Min()**

1. Find root with minimum key.
2. Remove it from heap.
3. Take its children (which form a reversed binomial heap).
4. Union this heap with the remaining heap.

Time:

```
O(log n)
```

---

## **5️⃣ Decrease-Key(x, newKey)**

Decrease the value of node x.

Steps:

1. Assign newKey to x.
2. **Bubble up**: if parent is larger, swap with parent.
3. Continue until heap property is restored.

Time:

```
O(log n)
```

---

## **6️⃣ Delete(x)**

Delete node x.

Steps:

1. Decrease-Key(x, –∞)
2. Extract-Min()

Time:

```
O(log n)
```

---

# 🔹 6. Time Complexity Summary

| Operation    | Time     |
| ------------ | -------- |
| Insert       | O(log n) |
| Merge        | O(log n) |
| Find-Min     | O(log n) |
| Extract-Min  | O(log n) |
| Decrease-Key | O(log n) |
| Delete       | O(log n) |

---

# ⭐ Why Binomial Heap Exists?

Because **binary heap merging is slow** (O(n)),
while **binomial heap merging is fast** (O(log n)).

Used in:

* Prim’s MST algorithm
* Dijkstra’s algorithm (historically)
* Any application needing fast mergeable priority queues

