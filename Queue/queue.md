## Queue in Data Structures
A **queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle. This means the element that is inserted first is removed first. It is widely used in scheduling, buffering, and handling requests in real-world applications.

### **Types of Queue**
1. **Simple Queue** - Elements are inserted at the rear and deleted from the front.
2. **Circular Queue** - The last position connects back to the first, optimizing space usage.
3. **Priority Queue** - Each element has a priority, and the highest priority element is dequeued first.
4. **Double-ended Queue (Deque)** - Elements can be inserted and removed from both ends.

### **Advantages of Queue**
- Maintains order in processing elements.
- Efficient for handling requests in real-time applications like CPU scheduling.
- Prevents overflow in data buffering situations.
- Used in breadth-first search (BFS) algorithms in graphs.

### **Disadvantages of Queue**
- Fixed size in array-based implementation leads to memory wastage or overflow.
- Deletion is only allowed from the front, limiting flexibility.
- Insertion and deletion require shifting elements in a simple array-based queue.

---

This C program implements a **queue** using an **array**. Let's go through its components step by step:

### 1. **Defining the Queue Structure**
```c
#define MAX 5
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;
```
- `MAX` is the maximum size of the queue.
- `Queue` is a structure that holds an array `items` to store elements.
- `front` and `rear` are indices to track the front and rear of the queue.

### 2. **Initializing the Queue**
```c
void initialize(Queue *q) {
    q->front = -1;
    q->rear = -1;
}
```
- Sets `front` and `rear` to `-1`, indicating that the queue is empty.

### 3. **Checking if the Queue is Empty or Full**
```c
int isEmpty(Queue *q) {
    return q->front == -1;
}
int isFull(Queue *q) {
    return q->rear == MAX - 1;
}
```
- `isEmpty()` returns `1` if the queue has no elements.
- `isFull()` returns `1` if the queue is full.

### 4. **Enqueue (Adding Elements)**
```c
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
```
- If the queue is full, it prints an error message.
- If inserting the first element, `front` is set to `0`.
- The `rear` index is incremented, and the new value is stored.

### 5. **Dequeue (Removing Elements)**
```c
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
```
- If the queue is empty, it returns `-1`.
- The value at `front` is removed, and `front` is incremented.
- If all elements are removed, the queue is reset.

### 6. **Displaying the Queue**
```c
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
```
- Prints all elements from `front` to `rear`.

### 7. **Main Function**
```c
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
```
- Demonstrates the queue operations:
  - Enqueues `10, 20, 30`
  - Dequeues one element
  - Enqueues more values
  - Displays the queue at each step

### **Key Takeaways**
- The queue follows **FIFO (First In, First Out)**.
- Uses an array of fixed size (`MAX = 5`).
- Efficient `enqueue()` and `dequeue()` operations.
- When the queue is empty, it resets `front` and `rear`.
