#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to search for an element in the linked list
int searchElement(struct Node* head, int key) {
    struct Node* current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == key) {
            return position; // Element found, return its position
        }
        current = current->next;
        position++;
    }
    return -1; // Element not found
}

int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    int n, i, value, key, result;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    // Create the linked list
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);

        struct Node* newNode = createNode(value);
        if (head == NULL) {
            head = newNode; // Set the first node as head
        } else {
            temp->next = newNode; // Link the previous node to the new node
        }
        temp = newNode;
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Search for the element
    result = searchElement(head, key);
    if (result != -1) {
        printf("Element %d found at position %d.\n", key, result);
    } else {
        printf("Element %d not found in the linked list.\n", key);
    }

    // Free memory (optional, but good practice)
    while (head != NULL) {
        struct Node* next = head->next;
        free(head);
        head = next;
    }

    return 0;
}
