#include <iostream>
#define MAX 100    // Maximum size of the stack
using namespace std;

// Stack class definition
class Stack {
private:
    int arr[MAX];  // Array to store stack elements
    int top;       // Index of the topmost element

public:
    // Constructor to initialize stack
    Stack() {
        top = -1;  // -1 indicates stack is currently empty
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == MAX - 1;  // Stack is full when top index reaches MAX - 1
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;  // Stack is empty when top = -1
    }

    // Function to push (insert) an element onto the stack
    void push(int elem) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << elem << endl;
            return;  // No space left to insert
        }
        arr[++top] = elem;  // Increment top and add the element
        cout << elem << " pushed onto stack." << endl;
    }

    // Function to pop (remove) the top element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return -1;  // Indicates no element to remove
        }
        return arr[top--];  // Return top element and then decrement top
    }

    // Function to peek (view) the top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty! Nothing to peek." << endl;
            return -1;  // Indicates empty stack
        }
        return arr[top];  // Return the topmost element
    }

    // Function to display all elements of the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function: Menu-driven program
int main() {
    Stack s;       // Create stack object
    int choice, elem;

    while (true) {
        cout << "\n--- STACK MENU ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter element to push: ";
            cin >> elem;
            s.push(elem);
            break;

        case 2:
            elem = s.pop();
            if (elem != -1)
                cout << elem << " popped from stack." << endl;
            break;

        case 3:
            elem = s.peek();
            if (elem != -1)
                cout << "Top element is: " << elem << endl;
            break;

        case 4:
            s.display();
            break;

        case 5:
            cout << "Exiting program." << endl;
            return 0;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}
