/*
    @author      : Amirul Islam
    @topic       : Binary Search Tree
    @description : Insert O( log N ), Seach O( log N ), Delete O( log N ), Print O( N )
*/

#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

node* FindMin(node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

node* getNewNode(int data) {
    node* new_node = new node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

node* insert(node *root, int data) {
    if (root == NULL) {
        root = getNewNode(data);
    }
    else if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

bool search(node *root, int data) {
    if (root == NULL) return false;
    else if (root->data == data) return true;
    else if (data <= root->data) return search(root->left, data);
    else return search(root->right, data);
}

struct node* Delete(struct node* root, int data) {
    if (root == NULL) return root;
    else if (data < root->data) root->left = Delete(root->left, data);
    else if (data > root->data) root->right = Delete(root->right, data);
    else { // FOUND
        // Case 1: No Child
        if (root->left == NULL && root->right == NULL) {
            delete(root);
        }
        // Case 2: One Child
        else if (root->left == NULL) {
            struct node* tmp = root;
            root = root->right;
            delete(tmp);
        }
        else if (root->right == NULL) {
            struct node* tmp = root;
            root = root->left;
            delete(tmp);
        }
        // Case 3: Two children
        else {
            struct node* tmp = FindMin(root->right);
            root->data = tmp->data;
            root->right = Delete(root->right, tmp->data);
        }
    }
    return root;
};

void PreOrder(node *root) {
    if (root == NULL) return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
} 

// PRINT IN SORTED ORDER
void InOrder(node *root) {
    if (root == NULL) return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void PostOrder(node *root) {
    if (root == NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " "; 
}

int main() {
    node *root = NULL;

    /*
	        35
			   / \
			  10  55
			 / \ 
			5  15
    */

    // insert data
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 35);
    root = insert(root, 55);
    root = insert(root, 5);
    
    // search data
    cout << "Enter a number to search: ";
    int n; cin >> n;
    if (search(root, n)) cout << n << " FOUND!\n";
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
