#include <iostream>
#define MAX 5

using namespace std;

class CircularQueue {
private:
    int items[MAX];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        items[rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int value = items[front];
        if (front == rear) {
            front = rear = -1; // Reset when queue becomes empty
        } else {
            front = (front + 1) % MAX;
        }
        return value;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};
void option(){
	cout << "1) push" <<endl;
	cout << "2) pop" <<endl;
	cout << "3) Display" <<endl;
	cout << "4) Exit"<<endl;
}

int main() {
    CircularQueue q;
    int ch;
    while(1){
	int num;
	option();
	cout << "Enter your choice: ";
	cin >>ch;
	switch (ch){
		case 1:
			cout << "Enter value: ";
			cin >> num;
			q.enqueue(num);
			q.display();
			break;
		case 2:
			num = q.dequeue();
			cout << "Popped value "<<num;
			q.display();
			break;
		case 3:
			q.display();
			break;
		case 4:
			exit(0);
				
		default:
			cout << "Entered wrong choice";	
    	}
    }
    return 0;
}

