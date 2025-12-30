# Stack.java

Comparison of the 5 stack options in Java:

1️⃣ Built-in Stack

2️⃣ Custom Stack (array-based)

3️⃣ LinkedList

4️⃣ ArrayList

5️⃣ ArrayDeque ( ✅ BEST )

---

### 1️⃣ Built-in Stack<E> (java.util.Stack)

- Old Java class
- Extends Vector
- Uses array internally
- Thread-safe (synchronized)


How it works
```
Stack<Integer> s = new Stack<>();
s.push(10);
s.pop();
```

✅ Pros

- Easy to use
- Thread-safe

❌ Cons 

- Synchronization overhead (slow)
- Legacy class (pre-Java 1.2 design)
- Not recommended anymore


Performance

Time: O(1) push/pop

Slower than all modern options


---

### 2️⃣ Custom Stack (Array-based)

- You manually manage array + top pointer

```
int[] stack = new int[100];
int top = -1;
```

Pros

✔ Fastest (no abstraction overhead)
✔ Best cache locality
✔ Full control

Cons ❌

Fixed size (unless you write resizing logic)

More code, more bugs


Performance

Time: O(1) push/pop

Space: contiguous memory


Verdict

🏎 Fastest possible stack

> Used in competitive programming & embedded systems




---

3️⃣ Stack using LinkedList

What it is

Doubly linked list

Stack operations mapped to head


LinkedList<Integer> s = new LinkedList<>();
s.push(10);
s.pop();

Pros

✔ Dynamic size
✔ No overflow
✔ Easy implementation

Cons ❌

Extra memory for pointers

Cache-unfriendly

Slower than array-based stacks


Performance

Time: O(1) push/pop

Higher constant cost


Verdict

❌ Never best choice

> Only useful when frequent middle insertions are needed (not stack!)




---

4️⃣ Stack using ArrayList

What it is

Resizable array

Stack simulated using add() and remove(size-1)


ArrayList<Integer> s = new ArrayList<>();
s.add(10);
s.remove(s.size()-1);

Pros

✔ Dynamic resizing
✔ Cache-friendly
✔ Better than LinkedList

Cons ❌

Resize cost (rare but expensive)

Not stack-specific API


Performance

Amortized O(1) push/pop

Occasional O(n) resize


Verdict

⚠ Acceptable, but not ideal


---

5️⃣ ArrayDeque<E> ⭐ (The King)

What it is

Resizable circular array

Designed for stack & queue

No synchronization


ArrayDeque<Integer> s = new ArrayDeque<>();
s.push(10);
s.pop();

Pros

✔ Fast
✔ Dynamic
✔ Cache-friendly
✔ No legacy overhead

Cons ❌

Not thread-safe (usually fine)


Performance

O(1) push/pop

Faster than Stack & LinkedList


Verdict

👑 BEST CHOICE IN JAVA

> Official Java docs recommend this.




---

🔥 Final Efficiency Ranking (Best → Worst)

Real-world / Interview / Production

1️⃣ Custom Stack (array)
2️⃣ ArrayDeque
3️⃣ ArrayList
4️⃣ LinkedList
5️⃣ Stack (legacy)


---

Exam-safe theoretical ordering

1️⃣ LinkedList (dynamic, no overflow)
2️⃣ Array-based stack
3️⃣ Stack
4️⃣ ArrayList
5️⃣ ArrayDeque

(Yes — exams are sometimes dumb. Play the game.)


---

Key Confusion You Had (Now Fixed)

> ❓ “Is LinkedList more efficient than stack?”



Correct answer:

In C theory → Yes (dynamic memory)

In Java systems → ❌ No

In real performance → ❌ No

In exams → Sometimes yes



---

Kakashi-style final advice 🥷

Use:

ArrayDeque → real apps

Custom array stack → speed-critical

LinkedList → never for stacks

Stack class → only when forced


If you want:

📌 MCQ traps

📌 Interview Q&A

📌 Code benchmarks

📌 Memory layout diagrams


Say “unlock next level” and we go Minato-speed 🚀
