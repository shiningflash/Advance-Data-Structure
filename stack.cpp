#include <bits/stdc++.h>
using namespace std;
#define SIZE 10

class mystack {
    int *arr;
    int top;
    int capacity;

public:
    mystack(int size = SIZE);
    void push(int);
    int pop();
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

mystack::mystack(int size) {
    arr = new int[size];
    capacity = size;
    top = -1;
}

void mystack::push(int item) {
    if (isFull()) {
        printf("Eroor: stack overflow\n");
        return;
    }
    arr[++top] = item;
}

int mystack::pop() {
    if (isEmpty()) {
        printf("Error: stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return arr[top--];
}

int mystack::peek() {
    if (isEmpty()) {
        printf("Error: stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return arr[top];
}

int mystack::size() {
    return top + 1;
}

bool mystack::isEmpty() {
    return top == -1;
}

bool mystack::isFull() {
    return top == capacity - 1;
}

void print_stack(mystack st) {
    while (!st.isEmpty()) {
        printf("%d ", st.pop());
    }
    printf("\n");
}

int main() {
    mystack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    print_stack(st); // 4 3 2 1
    printf("%d\n", st.pop()); // 4
    printf("%d\n", st.peek()); // 3
    print_stack(st); // 3 2 1
    return 0;
}
