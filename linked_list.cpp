#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void InsertBegin(Node** head, int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if (*head != NULL) temp->next = *head;
    *head = temp;
}

void print(Node* temp) {
    printf("List is:");
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Insert(Node** head, int data, int pos) {
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;

    // pos at the beginning
    if (pos == 1) {
        temp1->next = *head;
        *head = temp1;
        return;
    }

    // n'th position
    Node* temp2 = *head;
    for (int i = 1; i < pos - 1; i++) {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void Delete(Node** head, int pos) {
    Node* temp1 = *head;

    // first Node, pos = 1
    if (pos == 1) {
        *head = temp1->next;
        free(temp1); // deallocate the memory
        return;
    }

    // n'th position
    for (int i = 1; i < pos - 1; i++) {
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

Node* Reverse(Node* head) {
    Node *current, *prev, *next;
    current = head;
    prev = next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;
}

Node* Reverse_Recursive(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* temp = Reverse_Recursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

int main() {
    Node* head = NULL;
    for (int i = 5; i >= 1; i--) {
        InsertBegin(&head, i);
        print(head);
    }
    
    Insert(&head, 6, 6);
    print(head);
    Insert(&head, 7, 7);
    print(head);

    Delete(&head, 7);
    print(head);
    Delete(&head, 6);
    print(head);
    Delete(&head, 1);
    print(head);

    // Node* rev = Reverse(head);
    // print(rev);
    
    Node* rec_rev = Reverse_Recursive(head);
    print(rec_rev);
}

/*
OUTPUT

List is: 5
List is: 4 5
List is: 3 4 5
List is: 2 3 4 5
List is: 1 2 3 4 5
List is: 1 2 3 4 5 6
List is: 1 2 3 4 5 6 7
List is: 1 2 3 4 5 6
List is: 1 2 3 4 5
List is: 2 3 4 5
List is: 5 4 3 2
*/
