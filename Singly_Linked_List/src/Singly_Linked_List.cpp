#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Singly Linked List class
class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        cout << data << " inserted at the beginning.\n";
    }

    // Insert at end
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            cout << data << " inserted at the end.\n";
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
        cout << data << " inserted at the end.\n";
    }

    // Insert at position
    void insertAtPosition(int data, int pos) {
        if (pos < 1) {
            cout << "Invalid position!\n";
            return;
        }

        if (pos == 1) {
            insertAtBeginning(data);
            return;
        }

        Node* newNode = new Node(data);
        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Position out of bounds!\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        cout << data << " inserted at position " << pos << ".\n";
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty! Cannot delete.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        cout << temp->data << " deleted from beginning.\n";
        delete temp;
    }

    // Delete from end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty! Cannot delete.\n";
            return;
        }

        if (head->next == nullptr) {
            cout << head->data << " deleted from end.\n";
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;

        cout << temp->next->data << " deleted from end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete from specific position
    void deleteFromPosition(int pos) {
        if (head == nullptr) {
            cout << "List is empty! Cannot delete.\n";
            return;
        }

        if (pos < 1) {
            cout << "Invalid position!\n";
            return;
        }

        if (pos == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds!\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        cout << toDelete->data << " deleted from position " << pos << ".\n";
        delete toDelete;
    }

    // Display all nodes
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, data, pos;

    while (true) {
        cout << "\n--- SINGLY LINKED LIST MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                list.insertAtBeginning(data);
                break;

            case 2:
                cout << "Enter data: ";
                cin >> data;
                list.insertAtEnd(data);
                break;

            case 3:
                cout << "Enter data and position: ";
                cin >> data >> pos;
                list.insertAtPosition(data, pos);
                break;

            case 4:
                list.deleteFromBeginning();
                break;

            case 5:
                list.deleteFromEnd();
                break;

            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                list.deleteFromPosition(pos);
                break;

            case 7:
                list.display();
                break;

            case 8:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}        return;
    }

    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    printf("%d deleted from position %d\n", toDelete->data, pos);
    free(toDelete);
}

// Delete from the end
void deleteFromEnd(Node **head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node *temp = *head;

    if (temp->next == NULL) {
        printf("%d deleted from the end\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next->next != NULL)
        temp = temp->next;

    printf("%d deleted from the end\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

// Display the linked list
void display(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with menu
int main() {
    Node *head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertAtPosition(&head, data, pos);
                break;
            case 4:
                deleteFromBeginning(&head);
                break;
            case 5:
                deleteFromEnd(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteFromPosition(&head, pos);
                break;
            case 7:
                display(head);
                break;
            case 8:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
