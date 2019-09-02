#include <bits/stdc++.h>
using namespace std;
#define SIZE 10

class Queue {
    int *arr;
    int head;
    int tail;
    int capacity;

public:
    Queue(int size = SIZE);
    void enqueue(int);
    int dequeue();
    int size();
    bool isEmpty();
    bool isFull();
};

Queue::Queue(int size) {
    arr = new int[size];
    head = 0;
    tail = 0;
    capacity = size;
}

void Queue::enqueue(int item) {
    if (isFull()) {
        printf("Error: Queue is full\n");
        return;
    }
    arr[tail] = item;
    tail = (tail + 1) % capacity;
}

int Queue::dequeue() {
    if (isEmpty()) {
        printf("Error: Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    int item = arr[head];
    head = (head + 1) % capacity;
    return item;
}

bool Queue::isEmpty() {
    return tail == head;
}

bool Queue::isFull() {
    return (tail + 1) % capacity == head;
}

int main() {
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    printf("%d\n", q.dequeue()); // 1
    printf("%d\n", q.dequeue()); // 2
    printf("%d\n", q.dequeue()); // Error: Queue is empty
    return 0;
}
