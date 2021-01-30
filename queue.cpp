#include <bits/stdc++.h>
using namespace std;
#define SIZE 10

class Queue {
    
    public:
        int *arr;
        int head;
        int tail;
        int capacity;

    Queue(int size) {
        arr = new int[size];
        head = 0;
        tail = 0;
        capacity = size;
    }

    void enqueue(int item) {
        if (isFull()) {
            printf("Error, stack is full\n");
            exit(EXIT_FAILURE);
        }
        arr[tail] = item;
        tail = (tail+1) % capacity;
    }

    int dequeue() {
        if (isEmpty()) {
            printf("Error, stack is empty\n");
            exit(EXIT_FAILURE);
        }
        int item = arr[head];
        head = (head + 1) % capacity;
        return item;
    }

    bool isFull() {
        return ((tail + 1) % capacity == head);
    }

    bool isEmpty() {
        return head == tail;
    }
};

int main() {
    Queue q(5);
    for (int i = 0; i < 4; i++) q.enqueue(i+1);
    for (int i = 0; i < 5; i++) printf("%d\n", q.dequeue());
}
