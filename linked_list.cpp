#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void InsertBeginning(Node** head, int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if (*head != NULL) temp->next = *head;
    *head = temp;
}

void Print(Node* temp) {
    printf("List is:");
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Insert(Node** head, int val, int pos) {
    Node* temp1 = new Node();
    temp1->data = val;
    temp1->next = NULL;

    // position at the beginning
    if (pos == 1) {
        temp1->next = *head;
        *head = temp1;
        return;
    }
    // n-th position
    Node* temp2 = *head;
    for (int i = 1; i < pos-1; i++) {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void Delete(Node** head, int pos) {
    Node* temp1 = *head;
    if (pos == 1) {
        *head = temp1->next;
        free(temp1);
        return;
    }
    for (int i = 1; i < pos-1; i++) {
        temp1 = temp1->next;
    }
    Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
}

Node* Reverse(Node* head) {
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    next = NULL;
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
    Node* head = new Node();
    // for (int i = 1; i < 5; i++) {
    //     printf("Insert %d\n", i);
    //     InsertBeginning(&head, i);
    //     Print(head);
    // }
    Insert(&head, 1, 1); // value 1, pos 1
    Insert(&head, 2, 2); // value 2, pos 2
    Insert(&head, 3, 3); // value 3, pos 3
    Insert(&head, 4, 1); // value 4, pos 1
    Print(head);
    // Delete(&head, 1); // pos 1
    // Print(head);
    // Delete(&head, 2); // pos 2
    // Print(head);
    Node* rev = Reverse_Recursive(head);
    Print(rev);
}
