// AVL Tree
// - self balancing Binary Search Tree
// - Adelson-Velsky and Landis Tree

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    int height;
} Node;


// ============ Functions that Help INSERT() ============

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* root) {
    if (root == NULL) { return 0; }
    return root->height;
}

int getBalance(Node* node) {
    // balance factor is a measure of the height difference between the left and right subtrees of a node
    // Acceptable balance factors: { -1, 0, 1 }
    // bf = -2 and lower --> Left rotate
    // bf = +2 and more  --> Right rotate
    if (node == NULL) { return 0; } // Null node has balance factor 0
    return height(node->left) - height(node->right);
}

Node* createNode(int newVal) {
    Node* newNode = (Node*)malloc(sizeof(*newNode));
    if (newNode == NULL) { return NULL; }
    newNode->val = newVal;
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->height = 1;
    return newNode;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* root, int newVal) {
    if (root == NULL)
        return createNode(newVal);

    if (newVal < root->val)
        root->left = insert(root->left, newVal);
    else if (newVal > root->val)
        root->right = insert(root->right, newVal);
    else // Equal values are not allowed in AVL tree
        return root;

    // Update height of current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor to check if the node became unbalanced
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && newVal < root->left->val)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && newVal > root->right->val)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && newVal > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && newVal < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// // What is rotating?
// // on an imbalanced AVL tree, the root node gets to be shifted around to satisfy the balance factor

// Node* leftRotate(Node* root) {
//     Node* nRoot = root->right;
//     Node* child = nRoot->left;

//     // perform rotation
//     nRoot->left = root;
//     root->right = child;

//     // update height
//     root->height = 1 + max(height(root->left), height(root->right));
//     nRoot->height = 1 + max(height(nRoot->left), height(nRoot->right));

//     return nRoot;
// }

// Node* rightRotate(Node* root) {
//     Node* nRoot = root->left;
//     Node* child = nRoot->right;

//     // perform rotation
//     nRoot->right = root;
//     root->left = child;

//     // update height
//     root->height = 1 + max(height(root->left), height(root->right));
//     nRoot->height = 1 + max(height(nRoot->left), height(nRoot->right));

//     return nRoot;
// }

// Node* insert(Node* root, int newVal) {
//     // Base Case 
//     if (root == NULL) { return createNode(newVal); }

//     // Perform Recursive Insert (normal BST)
//     if (newVal < root->val) {
//         root->left = insert(root->left, newVal);
//     } else if (newVal > root->val) {
//         root->right = insert(root->right, newVal);
//     } else {
//         return root; // equal values are invalid in AVL
//     }
//     root->height = 1 + max(height(root->left), height(root->right));

//     // Perform AVL Balancing (4 cases)
//     int balance = getBalance(root); 
//     if ( balance > 1 && newVal < root->left->val )      // Left
//         return rightRotate(root);
//     if ( balance < -1 && newVal > root->right->val )    // Right 
//         return leftRotate(root);
//     if ( balance > 1 && newVal > root->left->val ) {    // Left Right
//         root->left = leftRotate(root->left);
//         return rightRotate(root);
//     }
//     if ( balance < -1 && newVal < root->right->val ) {  // Right Left
//         root->right = rightRotate(root->right);
//         return leftRotate(root);
//     }

//     return root; // no balancing needed
// }

void inOrderT(Node* root) {
    if (root != NULL) {
        inOrderT(root->left);
        printf("%d ", root->val);
        inOrderT(root->right);
    }
}


void freeTree(Node* root){
    if(root != NULL) {
        if ( root->left != NULL ) freeTree(root->left); 
        if ( root->right != NULL ) freeTree(root->right); 
        free(root);
        root = NULL;
    }
}

int main(void) {
    
    Node* root = NULL;

    // Inserting keys into the AVL tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of AVL tree: ");
    inOrderT(root);
    printf("\n");

    freeTree(root);

    return 0;
}