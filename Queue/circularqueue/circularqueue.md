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

This C program implements a **circular queue** using an **array**.

### 1. **Defining the Circular Queue Structure**
```c
#define MAX 5
typedef struct {
    int items[MAX];
    int front, rear;
} CircularQueue;
```
- `MAX` is the maximum size of the queue.
- `CircularQueue` is a structure that holds an array `items` to store elements.
- `front` and `rear` track the front and rear positions.

### 2. **Initializing the Circular Queue**
```c
void initialize(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}
```
- Sets `front` and `rear` to `-1`, indicating that the queue is empty.

### 3. **Checking if the Queue is Empty or Full**
```c
int isEmpty(CircularQueue *q) {
    return q->front == -1;
}
int isFull(CircularQueue *q) {
    return (q->rear + 1) % MAX == q->front;
}
```
- `isEmpty()` returns `1` if the queue is empty.
- `isFull()` returns `1` if the queue is full.

### 4. **Enqueue (Adding Elements)**
```c
void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}
```
- If the queue is full, it prints an error message.
- If inserting the first element, `front` is set to `0`.
- The `rear` index wraps around circularly using `(q->rear + 1) % MAX`.

### 5. **Dequeue (Removing Elements)**
```c
int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; // Reset when queue becomes empty
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return value;
}
```
- If the queue is empty, it returns `-1`.
- The value at `front` is removed, and `front` is updated circularly.
- If all elements are removed, the queue is reset.

### 6. **Displaying the Circular Queue**
```c
void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
```
- Prints all elements from `front` to `rear`, handling the circular wrap-around.

### 7. **Main Function**
```c
int main() {
    CircularQueue q;
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
- Demonstrates the circular queue operations:
  - Enqueues `10, 20, 30`
  - Dequeues one element
  - Enqueues more values
  - Displays the queue at each step

### **Key Takeaways**
- The circular queue efficiently uses space by wrapping around when reaching the end.
- It follows **FIFO (First In, First Out)** principle.
- Uses an array of fixed size (`MAX = 5`).
- Efficient `enqueue()` and `dequeue()` operations with circular indexing.

