#include <bits/stdc++.h>
using namespace std;
#define SIZE 10
 
class mystack {
    
    public:
        int *arr;
        int top;
        int capacity;

    mystack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }
    
    void push(int item) {
        if (isFull()) {
            printf("Error: stack overflow.");
            return;
        }
        arr[++top] = item;
    }
    
    void pop() {
        if (isEmpty()) {
            printf("Error: stack is empty.");
            return;
        }
        top--;
    }
    
    int peek() {
        if (isEmpty()) {
            printf("Error: stack is empty.");
            exit(EXIT_FAILURE);
        }
        return arr[top];
    }
    
    int size() {
        return top + 1;
    }
    
    bool isEmpty() {
        return top == -1;
    }
    
    bool isFull() {
        return top == capacity - 1;
    }
    
    void print_stack(mystack st) {
        while (!st.isEmpty()) {
            printf("%d ", st.peek());
            st.pop();
        }
        printf("\n");
    }
};

int main() {
    mystack st(10);
    st.push(1);
    st.push(2);
    st.push(3);
    st.print_stack(st);
    st.pop();
    st.pop();
    st.print_stack(st);
}
