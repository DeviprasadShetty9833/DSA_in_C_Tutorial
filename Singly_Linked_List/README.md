# Singly_Linked_List.c

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

# Singly_Linked_List:

<table>
<tr><td>

⏺️ A singly linked list is a linear data structure where each element (called a node) contains:

  - Data: The value stored in the node.

  - Next: A pointer/reference to the next node in the list.

⏺️ The last node’s next pointer is set to NULL to indicate the end of the list.

<details>
  <summary>Click to expand 🔻</summary>

<br> 🟠 Basic Operations:

```html

- Insertion: Add a node at the beginning, end, or a specific position.

- Deletion: Remove a node from the beginning, end, or a specific position.

- Traversal: Visit each node to access or display its value.

```

<br> 🟠 Advantages:

```html

• Dynamic size: Can grow or shrink as needed.

• Efficient insertions and deletions: No shifting of elements like arrays.

```

<br> 🟠 Applications:

```html

• Dynamic memory allocation.

• Implementation of stacks, queues, and other abstract data types.

• Undo functionality in text editors.

```

</tr></td>
</table>

</details> 

# 🔎  Insertion, Deletion, and Traversal of SLL.

📂 Source code to implement the basic operations (insertion, deletion, and traversal) of a singly linked list ( file : [src.c](https://github.com/DeviprasadShetty9833/Singly_Linked_List.c/blob/a17ce82cc276b7feacf7bbe80e9e9f04746a487f/src.c) )

<table>
<tr><td>

<br> ![1.](https://img.shields.io/badge/_1]_-Header_Files-000080?style=for-the-badge&logo=C&logoColor=white)   

*Code:*

```c
#include <stdio.h>   // For input/output functions like printf and scanf
#include <stdlib.h>  // For malloc and free functions

```

*In Plain English:*

> "Headers are like my brain. Without the captain, I wouldn’t know how to do basic things like print, read input, or manage memory."

</td></tr>
</table>

---

<table>
<tr><td>

<br> ![2.](https://img.shields.io/badge/_2]_-Node_Structure-000080?style=for-the-badge&logo=C&logoColor=white)   

*Code:*

```c
typedef struct Node {
    int data;              // Holds the value
    struct Node *next;     // Pointer to the next node
} Node;

```

*Explanation:*

> - 'typedef' enables you to use Node instead of writing struct Node every time.
> - 'Node' is the name of the structure.
> - 'data' is used to store the value contained in the Node.
> - 'next' is a pointer of type struct Node, which is used to point (store the address of) the next Node in the linked list, thus creating the chain-like structure.

*Example:*

```html
[Data(value) | next(address)]→
\___________________________/
              |
             Node

```

*In Plain English:*

> "This is a structure (called Node) that contains:  an integer data, and a pointer next that links to the next node in the list. Oh, and thanks to typedef, you don’t have to say ‘struct Node’ every time. You can just call me Node — way simpler!"

</td></tr>
</table>

---

<table>
<tr><td>

<br> ![3.](https://img.shields.io/badge/_3]_-Create_a_Node-000080?style=for-the-badge&logo=C&logoColor=white)   

*Code:*

```c

Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));  // Allocate memory

    newNode->data = data;                         // Set the value
    newNode->next = NULL;                         // Initially points to nothing

    return newNode;                               // Return the new node
}

```

*Algorithm:*

```html

CreateNode(data):
   1. Allocate memory for new node.
   2. Set newNode.data = data.
   3. Set newNode.next = NULL.
   4. Return newNode.

```

*Explanation:*

> - 'createNode' is function that returns a pointer to a Node.
> - 'newNode' is a pointer to a Node.
> - 'malloc' calculates the size in bytes needed to store a Node Structure and allocates memory from the heap(dynamic memory) and returns void pointer.
> - (Node*) before malloc converts (typecasting) the generic void pointer into a Node pointer.
> - int data is stored in newNode's data and newNode's next pointer points to NULL i.e does not point to anything.

*Example:*

```html
HEAD→[Data1 | next1]→[Data2 | next2]→[Data3 | next3]→NULL
      \_____________/ \_____________/  \_____________/
             |                |               |  
            Node             Node            Node
\__________________________________________________________/
                              |
                      Singly Linked List

```

*In Plain English:*

> "I made a new node for you. I saved your number in it. I made sure it doesn't point to any other node yet. Here’s your brand-new node, ready to put it into your list."

</td></tr>
</table>

---

<table>
<tr><td>

<br> ![4.](https://img.shields.io/badge/_4]_-Insert_At_Beginning-000080?style=for-the-badge&logo=C&logoColor=white)   

*Code:*

```c

void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);                 // Create node

    newNode->next = *head;                            // Point new node to current head
    *head = newNode;                                  // Move head to new node

    printf("%d inserted at the beginning\n", data);
}

```

*Algorithm:*

```html

InsertAtBeginning(head, data):
    1. newNode = CreateNode(data)
    2. Set newNode.next = head
    3. Set head = newNode
    4. Return head

```

*Explanation:*

> - 'Node **head' is a pointer to the head pointer of list. It allows modifying the actual head.
> - Link newNode to initial node pointed by head. 
> - Link head pointer to point new node, thus newNode becomes initial node.

*Example:*

```html

Position:        1           2   
List: head→[20 | next]→[30 | next]→NULL
Insert: [10 | next]→NULL at position 1 i.e before 20.

Step 1:

  [10 | next] ← newNode
         ↓ 
  head→[20 | next]→[30 | next]→NULL

Step 2:

  [10 | next] ← newNode
    ↑    ↓ 
  head→[20 | next]→[30 | next]→NULL
 
Step 3:

  head→[10 | next]→[20 | next]→[30 | next]→NULL

```

*In Plain English:*

> "I'll make a new node and save your number in it. Then, I'll link it to the current first node (if there is one). Now I’ll point the head to this new node — boom, it's leading the list!"

</td></tr>
</table>

---

<table>
<tr><td>

<br> ![5.](https://img.shields.io/badge/_5]_-Insert_At_End-000080?style=for-the-badge&logo=C&logoColor=white)   

*Code:*

```c

void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        printf("%d inserted at the end\n", data);
        return;
    }
    
    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;                     // Move to the last node
    temp->next = newNode;                      // Link new node at the end

    printf("%d inserted at the end\n", data);
}

```

*Algorithm:*

```html

InsertAtEnd(head, data):
    1. newNode = CreateNode(data)
    2. IF head is NULL:
          head = newNode
       ELSE:
          temp = head
          WHILE temp.next != NULL:
             temp = temp.next
          temp.next = newNode
    3. Return head

```

*Explanation:*

> - if the list is empty, connect the newNode to head.
> - temp points to initial node, pointed by head. 
> - Traverse till second last node. 
> - Next node of temp i.e. Last node points to newNode.

*Example:*

```html

Position:          1           2    
List:   head→[10 | next]→[20 | next]→NULL
Insert:  [30 | next]→NULL at position 3 i.e after 30.
                                
Step 1:

head→[10 | next]→[20 | next]→NULL
       ↑          
      temp 
 
Step 2: After while loop

head→[10 | next]→[20 | next]→[40 | next]→[50 | next]→NULL
                    ↑
                   temp  

Step 3:
              newNode → [30 | next]
                          ↑
head→[10 | next]→[20 | next]→NULL
                    ↑
                   temp  

Step 4:

head→[10 | next]→[20 | next]→[30 | next]→NULL
                    ↑            ↑
                   temp       newNode

```

*In Plain English:*

> "First, I'll make a new node and put the given data inside it. If the list is empty (no head), I’ll just make this new node the head. But if the list already has nodes, I’ll walk through each one until I find the last node — the one that points to NULL. Once I find it, I’ll tell it to point to the new node. Boom — new node is now the last in line!"


</td></tr>
</table>

---

<table>
<tr><td>

<br> ![6.](https://img.shields.io/badge/_6]_-Insert_At_Position-000080?style=for-the-badge&logo=C&logoColor=white)   

*Code:*

```c

void insertAtPosition(Node **head, int data, int pos) {
    if (pos < 1) { 
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(head, data);
        return;
    }

    Node *newNode = createNode(data);  // Create newNode

    Node *temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("%d inserted at position %d\n", data, pos);
}

```

*Algorithm:*

```html

InsertAtPosition(head, data, pos):
    1. IF pos == 1:
         Call InsertAtBeginning(head, data)
    2. temp = head
    3. FOR i from 1 to pos-1:
         IF temp == NULL:
            Print "Position out of bounds"
            RETURN head
         temp = temp.next
    4. newNode = CreateNode(data)
    5. newNode.next = temp.next
    6. temp.next = newNode
    7. Return head

```

*Explanation:*

> - Traverse the list until you reach two nodes before the desired insertion position.
> - At this point, the pointer temp is at the node just before the target position.
> - Link newNode's next to next node of temp.
> - temp's next points to newNode.

*Example:*

```html

Position:          1           2            3            4
List:   head→[10 | next]→[20 | next]→[40 | next]→[50 | next]→NULL
Insert:  [30 | next]→NULL at position 3 i.e before 40.
                                
Step 1:

head→[10 | next]→[20 | next]→[40 | next]→[50 | next]→NULL
       ↑          
      temp 
 
Step 2: After for loop

head→[10 | next]→[20 | next]→[40 | next]→[50 | next]→NULL
                    ↑
                   temp  

Step 3:
              newNode → [30 | next]
                                ↓ 
head→[10 | next]→[20 | next]→[40 | next]→[50 | next]→NULL
                    ↑
                   temp  

Step 4:
              newNode → [30 | next]
                          ↑      ↓ 
head→[10 | next]→[20 | next]  [40 | next]→[50 | next]→NULL
                    ↑
                   temp  

Step 5:

head→[10 | next]→[20 | next]→[30 | next]→[40 | next]→[50 | next]→NULL
                    ↑            ↑
                   temp       newNode




```


*In Plain English:*

> "First, I'll check if the position makes sense. If it's the first spot I’ll just insert it at the beginning — easy peasy. Otherwise, I’ll walk through the list node by node until I reach the place just before where the new node should go. If I reach the end before finding that spot, I’ll shout ‘out of bounds!’. But if I’m in the right place, I’ll: create the new node, link it to the next node, and adjust the current node to point to this new one. Boom! The new node is now exactly where you asked for."

</td></tr>
</table>

---

<table>
<tr><td>

<br> ![7.](https://img.shields.io/badge/_7]_-Delete_from_Beginning-000080?style=for-the-badge\&logo=C\&logoColor=white)

*Code:*

```c
void deleteFromBeginning(Node **head) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    Node *temp = *head;            // Store current head
    *head = (*head)->next;         // Move head to next node
    printf("%d deleted from beginning\n", temp->data);
    free(temp);                    // Free old head
}
```

*Algorithm:*

```html
DeleteFromBeginning(head):
    1. IF head == NULL:
          Print "List empty"
          RETURN
    2. temp = head
    3. head = head.next
    4. Print temp.data
    5. Free(temp)
```

*Explanation:*

* Check if the list is empty. If so, nothing to delete.
* Store the first node (`head`) in a temporary pointer.
* Move the `head` pointer to the second node.
* Free the memory of the old first node.

*Example:*

```html
head→[10 | next]→[20 | next]→[30 | next]→NULL

Step 1:

head→[10 | next]→[20 | next]→[30 | next]→NULL
       ↑          
      temp

Step 2: 

   → → → → → → → →
  ↑                     ↓
head [10 | next]→[20 | next]→[30 | next]→NULL
       ↑          
      temp 

Step 3: Free old node (10)

Result:
head→[20 | next]→[30 | next]→NULL
```

*In Plain English:*

> "I chop off the very first node, slide the head to the next one, and erase the old leader. Now the 2nd node is the new head of the list."

</td></tr>
</table>

---

<table>
<tr><td>

<br> ![8.](https://img.shields.io/badge/_8]_-Delete_from_End-000080?style=for-the-badge\&logo=C\&logoColor=white)

*Code:*

```c
void deleteFromEnd(Node **head) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    if ((*head)->next == NULL) {      // Only one node
        printf("%d deleted from end\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    Node *temp = *head;
    while (temp->next->next != NULL)  // Move to second-last node
        temp = temp->next;

    printf("%d deleted from end\n", temp->next->data);
    free(temp->next);                 // Free last node
    temp->next = NULL;                // Mark new end
}
```

*Algorithm:*

```html
DeleteFromEnd(head):
    1. IF head == NULL:
          Print "List empty"
          RETURN
    2. IF head.next == NULL:
          Free head
          head = NULL
          RETURN
    3. temp = head
    4. WHILE temp.next.next != NULL:
          temp = temp.next
    5. Print temp.next.data
    6. Free(temp.next)
    7. temp.next = NULL
```

*Explanation:*

* If the list is empty → nothing to delete.
* If there’s only one node → delete it and set head to `NULL`.
* Otherwise, traverse the list until you reach the second last node.
* Delete the last node.
* Make temp’s `next = NULL` (marking it as the end).

*Example:*

```html
head→[10 | next]→[20 | next]→[30 | next]→NULL

Step 1: temp = node 20 (second last)
Step 2: toDelete = node 30
Step 3: Free 30
Step 4: temp->next = NULL

Result:
head→[10 | next]→[20 | next]→NULL
```

*In Plain English:*

> "I walk to the second-last node, snip off the last one, and declare: ‘You’re the new end now!’."

</td></tr>
</table>

---

<table>
<tr><td>

<br> ![9.](https://img.shields.io/badge/_9]_-Delete_from_Position-000080?style=for-the-badge\&logo=C\&logoColor=white)

*Code:*

```c
void deleteFromPosition(Node **head, int pos) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        deleteFromBeginning(head);
        return;
    }

    Node *temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    printf("%d deleted from position %d\n", toDelete->data, pos);
    free(toDelete);
}
```

*Algorithm:*

```html
DeleteFromPosition(head, pos):
    1. IF head == NULL:
          Print "List empty"
          RETURN
    2. IF pos == 1:
          Call DeleteFromBeginning()
    3. temp = head
    4. FOR i from 1 to pos-1:
          temp = temp.next
          IF temp == NULL:
             Print "Out of bounds"
             RETURN
    5. toDelete = temp.next
    6. temp.next = toDelete.next
    7. Print toDelete.data
    8. Free(toDelete)
```

*Explanation:*

* Validate: if the list is empty or position < 1 → reject.
* If position = 1 → delete from beginning.
* Otherwise, move to the node before the target position.
* If position doesn’t exist → out of bounds.
* Adjust pointers: skip over the node to delete.
* Free the unwanted node.

*Example:*

```html
head→[10 | next]→[20 | next]→[30 | next]→[40 | next]→NULL
Delete position 3 (node 30)

Step 1: temp = node 20
Step 2: toDelete = node 30
Step 3: temp->next = node 40
Step 4: Free 30

Result:
head→[10 | next]→[20 | next]→[40 | next]→NULL
```

*In Plain English:*

> "I sneak up to the node before the target, cut the chain, and skip over the unwanted one. That node gets deleted, and the list continues smoothly."

</td></tr>
</table>

---

<table>
<tr><td>

<br> ![10.](https://img.shields.io/badge/_10]_-Display_Function-000080?style=for-the-badge\&logo=C\&logoColor=white)

*Code:*

```c
void display(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d → ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
```

*Algorithm:*

```html
Display(head):
    1. IF head == NULL:
          Print "List empty"
          RETURN
    2. temp = head
    3. WHILE temp != NULL:
          Print temp.data
          temp = temp.next
    4. Print NULL
```

*Explanation:*

* If list is empty → message.
* Otherwise → start from head.
* Print each node’s value, followed by an arrow.
* Stop when you reach `NULL`.

*Example:*

```html
head→[10 | next]→[20 | next]→[30 | next]→NULL

Output: 10 → 20 → 30 → NULL
```

*In Plain English:*

> "I call out each node in order, pointing to the next, until the end where I shout NULL — meaning no more nodes!"

</td></tr>
</table>

---

<table>
<tr><td>

<br> ![11.](https://img.shields.io/badge/_11]_-Main_Function-000080?style=for-the-badge\&logo=C\&logoColor=white)

*Code:*

```c
int main() {
    Node *head = NULL;   // Start with empty list

    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtPosition(&head, 25, 3);

    display(head);

    deleteFromBeginning(&head);
    deleteFromEnd(&head);
    deleteFromPosition(&head, 2);

    display(head);

    return 0;
}
```

*Explanation:*

* Starts with an empty list.
* Inserts: 20, 10 at beginning → list grows leftwards.
* Inserts: 30, 40 at end → list grows rightwards.
* Inserts: 25 at position 3 → inserted in middle.
* Displays current list.
* Deletes first node, last node, and node at position 2.
* Displays updated list.

*Sample Output:*

```html
20 inserted at the beginning
10 inserted at the beginning
30 inserted at the end
40 inserted at the end
25 inserted at position 3
List: 10 → 20 → 25 → 30 → 40 → NULL
10 deleted from beginning
40 deleted from end
25 deleted from position 2
List: 20 → 30 → NULL
```

*In Plain English:*

> "The main function is the stage manager: it tells insertions where to go, calls for deletions when someone must leave, and finally asks display to show the lineup of all surviving nodes."

</td></tr>
</table>


# Output:

| [![TOP](https://img.shields.io/badge/_🔺_-Navigate_to_TOP_↑_-blue?style=for-the-badge&labelColor=white)](#Singly_Linked_List) | [![DSA_Journal](https://img.shields.io/badge/Back_to-DSA_Journal-000080?style=for-the-badge&logo=C&logoColor=white)](https://github.com/DeviprasadShetty9833/DSA_Journal)  | [![My_Portfolio](https://img.shields.io/badge/Back_to-My_Portfolio-000000?style=for-the-badge&logo=GitHub&logoColor=white)](https://github.com/DeviprasadShetty9833/My_Portfolio) |
|---|---|---|


