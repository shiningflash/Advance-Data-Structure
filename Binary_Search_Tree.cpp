/*
    @author      : Amirul Islam
    @topic       : Binary Search Tree
    @description : Insert O( log N ), Seach O( log N ), Delete O( log N ), Print O( N )
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* Insert(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
    }
    else if (data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(Node* root, int data) {
    // Empty BST
    if (root == NULL) return false;
    
    // YES! FOUND ...
    if (data == root->data) return true;

    if (data < root->data) {
        return Search(root->left, data);
    }
    else {
        return Search(root->right, data);
    }
}

Node* FindMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* Delete(Node* root, int data) {
    // Empty 
    if (root == NULL) return root;
    
    else if (data < root->data) {
        Delete(root->left, data);
    }
    else if (data > root->data) {
        Delete(root->right, data);
    }

    // FOUND
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete(root);
        }
        // Case 2: One child
        else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete(temp);
        }
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete(temp);
        }
        // Case 3: Two children
        else {
            Node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

void PreOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
} 

// PRINT IN SORTED ORDER
void InOrder(Node* root) {
    if (root == NULL) return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void PostOrder(Node* root) {
    if (root == NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " "; 
}

int main() {
    Node* root = NULL;

    /*
	                    35
			   / \
			  10  55
			 / \ 
			5  15
    */

    // insert data
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 35);
    root = Insert(root, 55);
    root = Insert(root, 5);
    
    // search data
    cout << "Enter a number to search: ";
    int n; cin >> n;
    if (Search(root, n)) cout << n << " FOUND!\n";
    else cout << n << " NOT FOUND!\n";

    // delete data
    cout << "Enter a number to delete: ";
    cin >> n;
    root = Delete(root, n);
    cout << n << " DELETED!\n";

    // print data in different order
    cout << "Pre-oder: ";
    PreOrder(root);
    cout << "\n";
    
    cout << "In-order: ";
    InOrder(root); // ALWAYS SORTED OUTPUT
    cout << "\n";

    cout << "Post-order: ";
    PostOrder(root);
    cout << "\n";

    return 0;
}

/*
OUTPUT

Enter a number to search: 12
12 NOT FOUND!
Enter a number to delete: 15
15 DELETED!
Pre-oder: 35 10 5 55 
In-order: 5 10 35 55 
Post-order: 5 10 55 35 
*/
