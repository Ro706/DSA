#include <stdio.h>
#define MAX 5

// Queue structure
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Function to initialize the queue
void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Function to check if the queue is full
int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Function to enqueue an element
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to dequeue an element
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front++;
    if (q->front > q->rear) { // Reset queue when empty
        q->front = q->rear = -1;
    }
    return value;
}

// Function to display the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initialize(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);
    
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    display(&q);

    return 0;
}

