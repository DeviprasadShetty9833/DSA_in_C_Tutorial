#include <iostream>
#define MAX 100    // Maximum size of the stack
using namespace std;

// Stack class definition
class Stack {
private:
    int arr[MAX];  // Array to hold stack elements
    int top;       // Top pointer index

public:
    // Constructor to initialize stack
    Stack() {
        top = -1;  // -1 indicates stack is empty
    }

    // Function to check if stack is full
    bool isFull() {
        return top == MAX - 1;
    }

    // Function to check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to push an element onto the stack
    void push(int elem) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << elem << endl;
            return;
        }
        arr[++top] = elem;
        cout << elem << " pushed onto stack." << endl;
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return -1; // Return error value
        }
        return arr[top--];
    }

    // Function to display stack contents
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

// Main function: menu-driven program
int main() {
    Stack s;        // Create stack object
    int choice, elem;

    while (true) {
        cout << "\n--- STACK MENU ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
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
            s.display();
            break;

        case 4:
            cout << "Exiting program." << endl;
            return 0;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}
