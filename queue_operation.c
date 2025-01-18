#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Queue structure
struct Queue {
    int front, rear, size;
    int arr[MAX];
};

// Function to initialize the queue
void initializeQueue(struct Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->size == 0;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return queue->size == MAX;
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue overflow!\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->arr[queue->rear] = value;
    queue->size++;
    printf("%d enqueued into queue\n", value);
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow!\n");
        return -1;
    }
    int value = queue->arr[queue->front];
    queue->front = (queue->front + 1) % MAX;
    queue->size--;
    return value;
}

// Function to get the front element
int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->arr[queue->front];
}

// Function to display the queue
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->arr[(queue->front + i) % MAX]);
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front\n");
        printf("4. Display queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&queue, value);
                break;
            case 2:
                value = dequeue(&queue);
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                value = front(&queue);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 4:
                displayQueue(&queue);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
