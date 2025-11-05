# Stack.c

<br> ![Author: Deviprasad Shetty](https://img.shields.io/badge/Author-💫_Deviprasad%20Shetty-000000?style=for-the-badge&labelColor=white)
<br> 


# My Intro:
<br> Hi, 😃👋 I'm Deviprasad Shetty, highly passionate for coding, learning and exploring new fields in Computer Science domain. 
<br> I'm excited 😃 to dive deeper into my technical skills, collaborate with others, and take on projects that challenge me to grow. 
<br> Always eager to learn and connect with others who share similar interests! 🤗🧑‍💻
<br> 
| [![LinkedIn](https://img.shields.io/badge/LinkedIn-%230077B5?style=for-the-badge&logo=LinkedIn&logoColor=white)](https://linkedin.com/in/deviprasad-shetty-4bba49313) | [![Website](https://img.shields.io/badge/Website-indigo?style=for-the-badge&logo=About.me&logoColor=white)](https://yourwebsite.com/) | [![My Portfolio](https://img.shields.io/badge/My_Portfolio-000?style=for-the-badge&logo=GitHub&logoColor=white)](https://github.com/DeviprasadShetty9833/My_Portfolio)  |                      
|---|---|---|
<br> 

---

| [![DSA_Journal](https://img.shields.io/badge/Back_to-DSA_Journal-000080?style=for-the-badge&logo=C&logoColor=white)](https://github.com/DeviprasadShetty9833/DSA_Journal) | [![Resources](https://img.shields.io/badge/📚_Back_to-Resources-A52A2A?style=for-the-badge&logo=book&logoColor=white)](https://github.com/DeviprasadShetty9833/Resources) |
|---|---|

---

# Stack Using Linked List

📂 Source code to implement a Stack data structure using a Linked List ( file : [src.c](https://github.com/DeviprasadShetty9833/Stack.c/blob/3042d3b7210bfa0983b9baeb8796131376fa9f83/src/Stack_using_Linked_List.c) )

# Stack Using Array

📂 Source code to implement a Stack data structure using an Array ( file : [src.c](https://github.com/DeviprasadShetty9833/Stack.c/blob/027f8a82da96a8069a7457b443ac5d853a41f5ac/src/Stack_using_Array.c) )

<table>  
<tr><td>  
  ⏺️ A stack is a linear data structure that follows the LIFO (Last In, First Out) principle.

  ⏺️ The stack has a maximum size, and operations must check for overflow (too many elements) and underflow (trying to pop from an empty stack).

<details>  
  <summary>Click to expand 🔻</summary>  
<br> 🟠 Basic Operations:

```html

- Push (insert an element) onto the top of the stack unless the stack is full.

- Pop (remove an element) from the top of the stack unless the stack is empty.

- Peek (get top element) the top element without removing it unless the stack is empty.

- Display (print all elements in stack order)

```

<br> 🟠 Applications:

```html

- Expression evaluation (postfix/prefix).

- Undo/Redo in editors.

- Function call management in recursion.

- Browser forward/backward navigation.

```

<br> 🟠 Advantages:

```html

- Easy to implement with arrays or linked lists.

- Ensures controlled access order.

```

</details>  

</td></tr>  
</table>  

---

<table>
<tr><td>

<br> ![1.](https://img.shields.io/badge/_1]_-Headers-000080?style=for-the-badge&logo=C&logoColor=white)   


*Code:*

```c

#include <stdio.h>   // For printf and scanf  
#include <stdlib.h>  // For exit()

```

*In Plain English:*

> "These are my toolkits. stdio.h helps me talk to you (input/output), and stdlib.h helps me quit when things go wrong."

</td></tr>  
</table>  

---

<table>
<tr><td>

<br> ![2.](https://img.shields.io/badge/_2]_-Define_Stack-000080?style=for-the-badge&logo=C&logoColor=white)   


*Code:*

```c

#define MAX 3   // Maximum size of the stack

typedef struct {
    int arr[MAX];   // Array to hold stack elements
    int top;        // Index of the top element
} Stack;

```

*Explanation:*

> - MAX defines the stack’s capacity.
> - arr[MAX] is the container holding stack elements.
> - top keeps track of where the top element is (starts at -1 when empty).

*Example:*

```html
MAX = 3 : arr[3]

        2 |_______|   \
        1 |_______|    |- arr
        0 |_______|   /
top -> -1
```

*In Plain English:*

> "Think of me as a stack of plates. arr is the plate rack, and top tells me which plate is on the very top. Initially, top = -1, meaning the rack is empty."

</td></tr>  
</table>  

---

<table>
<tr><td>

<br> ![3.](https://img.shields.io/badge/_3]_-Initialize_Stack-000080?style=for-the-badge&logo=C&logoColor=white)   

*Code:*

```c

void initStack(Stack *s) {
    s->top = -1;   // Empty stack
}

```

*Algorithm:*

```html

1. Set s->top = -1.

```

*In Plain English:*

> "I reset the rack so it’s empty. No plates here yet."

</td></tr>  
</table>  

---

<table>
<tr><td>

<br> ![4.](https://img.shields.io/badge/_4]_-Push_Operation-000080?style=for-the-badge&logo=C&logoColor=white)   

*Code:*

```c

void push(Stack *s, int data) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", data);
        return;
    }
    s->arr[++(s->top)] = data;
    printf("%d pushed into stack\n", data);
}

```

*Algorithm:*

```html

1. Check if stack is full → if yes, print “Overflow”.
2. Increment top.
3. Place data at arr[top].

```

*Example:*

```html

Before push: [ ] (top = -1)

Push 10 → arr[0] = 10, top = 0
Push 20 → arr[1] = 20, top = 1

Stack: [10, 20] (20 is on top)

```

*In Plain English:*

> "I check if the rack is full. If not, I place your plate on the top and move the marker up. Voilà — plate stacked!"

</td></tr>  
</table>  

---

<table>
<tr><td>

<br> ![5.](https://img.shields.io/badge/_5]_-Pop_Operation-000080?style=for-the-badge&logo=C&logoColor=white)

*Code:*

```c

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow! Nothing to pop\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

```

*Algorithm:*

```html

1. Check if stack is empty → if yes, print “Underflow”.
2. Return arr[top].
3. Decrement top.

```

*Example:*

```html

Before Pop: [10, 20, 30] (top = 2)

Pop → returns 30, top = 1

Stack: [10, 20] (20 is on top)

```

*In Plain English:*

> "I look at the top plate, hand it back to you, and then move the marker down. One less plate in the stack!"

</td></tr>  
</table>  

---

<table>
<tr><td>

<br> ![6.](https://img.shields.io/badge/_6]_-Peek_Operation-000080?style=for-the-badge&logo=C&logoColor=white)

*Code:*

```c

int peek(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->arr[s->top];
}

```

*Algorithm:*

```html

1. Check if stack is empty → if yes, print "Empty".
2. Return arr[top].

```

*Example:*

```html

Before Peek: [10, 20, 30] (top = 2)

Peek → returns 30, top = 2

Stack: [10, 20, 30] (30 is on top)

```

*In Plain English:*

> "I won’t touch the stack, but I’ll tell you which plate is on top right now."

</td></tr>  
</table>  

---

<table>
<tr><td>

<br> ![7.](https://img.shields.io/badge/_7]_-Display_Stack-000080?style=for-the-badge&logo=C&logoColor=white)

*Code:*

```c

void display(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements (top to bottom):\n");
    for (int i = s->top; i >= 0; i--)
    printf("%d\n", s->arr[i]);
}

```


*Algorithm:*

```html

1. Check if stack is empty → if yes, print "Empty".
2. Display Stack arr.

```

*Example:*

```html

If stack = [10, 20, 30],
Output:
30
20
10

```

*In Plain English:*

> "I’ll show you all plates starting from the top. Like tipping the stack for a peek."

</td></tr>  
</table>  

---

<table>
<tr><td>

<br> ![8.](https://img.shields.io/badge/_8]_-Main_Function_(_Static_Input_)-000080?style=for-the-badge&logo=C&logoColor=white)

*Code:*

```c
int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    printf("Top element: %d\n", peek(&s));
    push(&s, 20);
    printf("Top element: %d\n", peek(&s));
    push(&s, 30);
    display(&s);
    printf("Top element: %d\n", peek(&s));
    push(&s, 40);
    printf("Popped: %d\n", pop(&s));
    printf("Top element: %d\n", peek(&s));
    display(&s);
    printf("Popped: %d\n", pop(&s));
    printf("Top element: %d\n", peek(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    

    return 0;
}
```

*Sample Output:*

```html

10 pushed into stack
Top element: 10
20 pushed into stack
Top element: 20
30 pushed into stack
Stack elements (top to bottom):
30
20
10
Top element: 30
Stack Overflow! Cannot push 40
Popped: 30
Top element: 20
Stack elements (top to bottom):
20
10
Popped: 20
Top element: 10
Popped: 10
Stack Underflow! Nothing to pop
```

</td></tr>  
</table>  

---

<table>
<tr><td>

<br> ![9.](https://img.shields.io/badge/_9]_-Main_Function_(_Menu_driven_Dynamic_Input_)-000080?style=for-the-badge&logo=C&logoColor=white)

*Code:*

```c
int main() {
    Stack s;
    initStack(&s);
    int choice, elem;

    while (1) {
        printf("Press \n 1. Push \n 2. Pop \n 3. Display \n 4. Exit \n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
              printf("Enter element to push: ");
              scanf("%d", &elem);
              push(&s, elem);
              break;

            case 2:
              elem = pop(&s);
              if (elem != -1)
              printf("%d popped from stack\n", elem);
              break;

            case 3:
              display(&s);
              break;

            case 4:
              printf("Exiting program.");
              return 0;

            default:
              printf("Invalid choice!\n");
        }
    }return 0;
}
```

*Sample Output:*

```html

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter element to push: 10
10 pushed onto stack

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter element to push: 20
20 pushed onto stack

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter element to push: 30
30 pushed onto stack

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack elements: 10 20 30

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
30 popped from stack

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack elements: 10 20

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
20 popped from stack

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
10 popped from stack

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
Stack Underflow! Cannot pop.

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 4
Exiting program.

```

</td></tr>  
</table>  
---

# Application-Based Questions
1. **Balancing Parentheses:**
- Write a program to check if an expression containing parentheses is balanced using a stack.
- Test it with the following cases and debug any issues:
- - Input: ((())) (Balanced)
  - Input: (())) (Unbalanced)
  - Input: (() (Unbalanced)
- What changes would you make to handle multiple types of brackets {}, [], and ()?

2. **Reversing Data Using a Stack:**
- Write a program to reverse a string using a stack.

3. **Infix to Postfix Conversion:**
- Write a program to convert an infix expression (e.g., A+BC) to a postfix expression (ABC+).
- Debug the following issues:
- - Incorrect precedence rules for operators.
  - Missing parentheses handling.

# Edge Case and Logical Thinking
1. Explain what happens in a stack when the push operation is performed on a full stack. How would you handle this
in Real-world applications where resizing is allowed?
2. A stack is often called a LIFO (Last In, First Out) data structure. Write an example scenario from real life that fits
this behavior and explain its relevance in programming.

# Challenge Questions
1. Modify a stack implemented using an array to allow **Multiple Stacks** within the same array. Implement the push,
pop, and display functions for this multi-stack configuration.
2. Implement a Min-Stack, a stack that allows retrieval of the minimum element in constant time. Use an auxiliary
stack to store the minimum values.
3. Write a Recursive implementation of the push and pop operations for a stack. Explain the difference in behavior
compared to iterative implementations.
4. Using a stack, **Evaluate the Postfix expression** 6 5 2 3 + 8 * + 3 + *. Write code to implement this and debug it for
edge cases (e.g., divide by zero, invalid input).
