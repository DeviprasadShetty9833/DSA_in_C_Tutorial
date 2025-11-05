#include <stdio.h>
#define MAX 100

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack *s, int elem) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", elem);
        return;
    }
    
    s->arr[++(s->top)] = elem;
    printf("%d pushed onto stack\n", elem);
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    }
    
    return s->arr[(s->top)--];
}

// Function to display the stack
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    
    printf("\n");
}

// Main function with menu
int main() {
    Stack s;
    initStack(&s);
    int choice, elem;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
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
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
