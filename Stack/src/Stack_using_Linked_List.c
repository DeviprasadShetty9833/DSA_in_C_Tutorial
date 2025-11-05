#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = data;
    newNode->next = NULL;
    
    return newNode;
}

// Function to push an element onto the stack
void push(Node **top, int data) {
    Node *newNode = createNode(data);
    
    newNode->next = *top;
    *top = newNode;
    
    printf("%d pushed onto stack\n", data);
}

// Function to pop an element from the stack
int pop(Node **top) {

    if (*top == NULL) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    }

    Node *temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;

    free(temp);
    printf("%d popped from stack\n", poppedData);

    return poppedData;
}

// Function to peek at the top element of the stack
int peek(Node *top) {

    if (top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

// Function to display the stack
void display(Node *top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    
    printf("Stack elements: ");
    Node *temp = top;
    
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    
    printf("NULL\n");
}

// Function to check if the stack is empty
int isEmpty(Node *top) {
    return top == NULL;
}

int main() {
    Node *top = NULL;
    int choice, data;
    
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Check if Empty\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
        case 1:
            printf("Enter data to push: ");
            scanf("%d", &data);
            push(&top, data);
            break;
            
        case 2:
            pop(&top);
            break;
            
        case 3:
            data = peek(top);
            if (data != -1)
                printf("Top element is %d\n", data);
            break;
            
        case 4:
            display(top);
            break;
            
        case 5:
            if (isEmpty(top))
                printf("Stack is empty.\n");
            else
                printf("Stack is not empty.\n");
            break;
            
        case 6:
            return 0;
            
        default:
            printf("Invalid choice!\n");
        }
    }
}
