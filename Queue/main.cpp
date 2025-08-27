#include<iostream>
using namespace std;

struct Queue {
    int size, front, rear;
    int *Q;
} *q = nullptr;

void create(int size) {
    q = new Queue;  // Allocate memory for the Queue structure
    q->size = size;
    q->Q = new int[size];
    q->front = q->rear = -1;
}

void enqueue(int x) {
    if (q->rear == q->size - 1) {  // Corrected condition for full queue
        cout << "Queue is full" << endl;
    } else {
        if (q->front == -1) {
            q->front = 0;  // If queue is empty, set front to 0
        }
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue() {
    int x = -1;
    if (q->front == -1) {  // Queue is empty
        cout << "Queue is empty" << endl;
    } else {
        x = q->Q[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;  // If there's only one element, reset the queue
        } else {
            q->front++;
        }
    }
    return x;
}

void display() {
    if (q->front == -1) {
        cout << "Queue is empty" << endl;
    } else {
        for (int i = q->front; i <= q->rear; i++) {
            cout << q->Q[i] << endl;
        }
    }
}

int main() {
    int size;
    cout << "Enter size" << endl;
    cin >> size;
    create(size);

    enqueue(5);
    enqueue(7);
    enqueue(9);
    enqueue(100);
    enqueue(5);
    enqueue(7);
    enqueue(9);
    enqueue(100);
    cout << endl;
    display();

    cout << "Removed: " << dequeue() << endl;
    cout << "Removed: " << dequeue() << endl;

    display();
    return 0;
}

