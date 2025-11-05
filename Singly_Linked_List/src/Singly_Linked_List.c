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

// Insert at the beginning
void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("%d inserted at the beginning\n", data);
}

// Insert at the end
void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        printf("%d inserted at the end\n", data);
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    printf("%d inserted at the end\n", data);
}

// Insert at a specific position
void insertAtPosition(Node **head, int data, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        insertAtBeginning(head, data);
        return;
    }

    Node *newNode = createNode(data);
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

// Delete from the beginning
void deleteFromBeginning(Node **head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    printf("%d deleted from the beginning\n", temp->data);
    free(temp);
}

// Delete from a specific position
void deleteFromPosition(Node **head, int pos) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
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
