# DSA_in_C_Tutorial


<br> ![Author: Deviprasad Shetty](https://img.shields.io/badge/Author-Deviprasad%20Shetty-000000?style=for-the-badge&labelColor=white)
<br> 


# My Intro:
<br> Hi, 😃👋 I'm Deviprasad Shetty, highly passionate for coding, learning and exploring new fields in Computer Science domain. 
<br> I'm excited 😃 to dive deeper into my technical skills, collaborate with others, and take on projects that challenge me to grow. 
<br> Always eager to learn and connect with others who share similar interests! 🤗🧑‍💻
<br> 
| [![LinkedIn](https://img.shields.io/badge/LinkedIn-%230077B5?style=for-the-badge&logo=LinkedIn&logoColor=white)](https://linkedin.com/in/deviprasad-shetty-4bba49313) | [![Website](https://img.shields.io/badge/Website-indigo?style=for-the-badge&logo=About.me&logoColor=white)](https://yourwebsite.com/) | [![My Portfolio](https://img.shields.io/badge/My_Portfolio-000?style=for-the-badge&logo=GitHub&logoColor=white)](https://github.com/DeviprasadShetty9833/My_Portfolio)  |                      
|---|---|---|
<br> 


# DSA Basics


<br> ![1.](https://img.shields.io/badge/_1]_-Overview%20of%20Data%20Structure-000080?style=for-the-badge&logo=C&logoColor=white)   

<table>
<tr><td>

<br> ▶️ A Data Structure is a way of organizing and storing data so that it can be accessed and worked with efficiently. 

<br> ▶️ They determine the organization of data, the operations that can be performed on the data, and the efficiency of these operations.

<br> ![1.1](https://img.shields.io/badge/_1.1_-Importance%20of%20Data%20Structures-000080?style=for-the-badge&logo=C&logoColor=white)   

<details>
  <summary>Click to expand</summary>

```html
 
1. Efficient Data Handling : Data structures allow for efficient organization and manipulation of data, enabling faster
processing.

2. Optimized Resource Usage : Proper data structures reduce memory and processing requirements.

3. Problem Solving : Many computational problems are best addressed by choosing the appropriate data structure.

4. Real-World Applications :

   •  Databases use trees and hash tables for efcient indexing.

   •  Search engines rely on graphs for ranking and searching.

   •  Compilers use stacks to evaluate expressions and manage function calls.

```

</details> 


<br> ![1.2](https://img.shields.io/badge/_1.2_-Key_Components_of_Data_Structures-000080?style=for-the-badge&logo=C&logoColor=white)   

<details>
  <summary>Click to expand</summary>
  
```html

1. Data Organization: The arrangement of data in memory (e.g., continuous blocks in arrays).

2. Data Manipulation: Operations like insertion, deletion, and updating of data.

3. Access Mechanism: Determines how data can be retrieved and stored efciently.

```

</details> 

<br> ![1.3](https://img.shields.io/badge/_1.3_-Classifcation_of_Data_Structures-000080?style=for-the-badge&logo=C&logoColor=white)   

<details>
  <summary>Click to expand</summary>

<br> Data structures can broadly be classifed into two categories:
  
```html

1. Primitive Data Structures
   • Basic data types that are directly operated upon by machine-level instructions.
   • Examples: Integers, Floats, Characters, Strings, and Boolean.

2. Non-Primitive Data Structures
   • More complex data structures built using primitive data types.
   • Examples:
      - Linear: Array, Linked List, Stack, Queue.
      - Nonlinear: Tree, Graph.

```

</details> 

<br> ![1.4](https://img.shields.io/badge/_1.4_-Types_of_Data_Structures-000080?style=for-the-badge&logo=C&logoColor=white)   

<details>
  <summary>Click to expand</summary>
  
```html

1. Linear Data Structures:
   • Data is arranged sequentially, and each element is connected to its previous and next element.
   • Examples: Arrays, Linked Lists, Stacks, Queues.

2. Nonlinear Data Structures:
   • Data is arranged in a hierarchical manner, with no strict sequence.
   • Examples: Trees, Graphs.

3. Static Data Structures:
   • Fixed size; memory is allocated at Compile-time.
   • Example: Array.

4. Dynamic Data Structures:
   • Flexible size; memory is allocated and deallocated at Runtime.
   • Example: Linked List.

```

</details> 

<br> ![1.5](https://img.shields.io/badge/_1.5_-Real_Life_Applications_of_Data_Structures-000080?style=for-the-badge&logo=C&logoColor=white)   

<details>
  <summary>Click to expand</summary>

<br> ▶️ A solid understanding of data structures is essential for designing efcient algorithms and writing optimized programs.

<br> ▶️ Selecting the right data structure for a given application is key to balancing speed, memory, and complexity. 

<br> ▶️ As computational demands grow, the choice and implementation of data structures become increasingly critical in developing scalable solutions.
  
```html

1. Arrays: Used in image processing, databases, and matrix manipulation.

2. Linked Lists: Basis for dynamic memory allocation, such as in compilers and real-time systems.

3. Stacks: Used for managing function calls in programming and expression evaluation.

4. Queues: Implemented in scheduling systems (CPU scheduling, printers).

5. Trees: Used in hierarchical databases, XML parsers, and fle systems.

6. Graphs: Essential for network routing, social media analytics, and web page ranking.

```

</details> 

</td></tr>
</table>

<br> ![2.](https://img.shields.io/badge/_2]_-Classifcation_of_Non_Primitive_Data_Structures-000080?style=for-the-badge&logo=C&logoColor=white)   

<table>
<tr><td>

<br> ![2.1](https://img.shields.io/badge/_2.1_-Linear_Data_Structures-000080?style=for-the-badge&logo=C&logoColor=white)   
Linear data structures organize data in a sequential manner, where elements are arranged in a line. 
Key Characteristics:

<br> ▶️ Elements are stored consecutively.

<br> ▶️ Traversal is straightforward (one-dimensional).

<br> ▶️ Fixed or variable size.

<table>
<tr><td>

Examples:

1. Array: A collection of elements stored in contiguous memory locations. Operations:

• Accessing: Constant time (using index).

• Searching: Linear search (O(n)) or binary search (O(log n) for sorted arrays).

• Insertion/Deletion: Expensive in terms of shifting elements.

• Applications: Used in matrices, image processing, and database indexing.

2. Linked List: A collection of nodes, where each node contains data and a pointer to the next node. Types:

• Singly Linked List: Points only to the next node.

• Doubly Linked List: Points to both next and previous nodes.

• Circular Linked List: Last node points to the frst node.

Advantages: Dynamic size, efcient insertion/deletion. Disadvantages: Higher memory usage due to pointers.

3. Stack: A collection following the Last In, First Out (LIFO) principle. Operations:

• Push: Insert an element.

• Pop: Remove the top element.

• Peek: View the top element.

• Applications: Used in recursion, expression evaluation, and undo functionality.

4. Queue: A collection following the First In, First Out (FIFO) principle. Types:

• Simple Queue.

• Circular Queue.

• Priority Queue.• Deque (Double-Ended Queue).

• Applications: Scheduling algorithms, resource sharing in operating systems.

</td></tr>
</table>

2.3.2 Nonlinear Data Structures

Nonlinear data structures organize data hierarchically or in an interconnected network.

Key Characteristics:

• Elements are not stored sequentially.

• Provide efcient relationships between data.

Examples:

1. Trees: A hierarchical structure consisting of nodes, with one root node and child nodes. Types:

• Binary Tree: Each node has at most two children.

• Binary Search Tree: Left child < root < right child.

• AVL Tree, Red-Black Tree: Balanced binary trees.

• Applications: Used in databases, fle systems, and network routing.

2. Graphs: Consist of vertices (nodes) and edges (connections). Types:

• Directed vs. Undirected Graphs.

• Weighted vs. Unweighted Graphs.

• Cyclic vs. Acyclic Graphs.

• Applications: Used in social networks, web page ranking, and shortest path algorithms.

</td></tr>
</table>
