#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int newVal){
    Node *newNode = (Node*)malloc(sizeof(*newNode));
    if ( newNode == NULL ) { return NULL; }
    newNode->val = newVal;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int newVal){
    
    if ( root == NULL ) { return createNode(newVal); }

    if ( newVal > root->val ) { 
        // input key is greater than the root key, insert in the right leaf
        root->right = insert(root->right, newVal); 
    }
    else if ( newVal < root->val ) {
        // input key is less than the root key, insert in the left leaf
        root->left = insert(root->left, newVal);
    }
    return root;
}

Node* getMax(Node* root) {
    // If there's no leaf to the right, then this is the maximum key value
    if ( root->right != NULL ){
        return getMax(root->right);
    }
    return root; 
}

void inOrderT(Node* root){
    if ( root != NULL ) {
        inOrderT(root->left);
        printf("%d ", root->val);
        inOrderT(root->right);
    }
}

Node* delete(Node* root, int toDelete){
    if (root == NULL ) { return root; }
    else if ( toDelete > root->val ) {
        root->right = delete(root->right, toDelete);
    }
    else if ( toDelete < root->val ) {
        root->left = delete(root->left, toDelete );
    }
    else if ( toDelete == root->val ) {
        // termination conditions
        // Case 1: no leaves, remove node
        // Case 2: one leaf, make leaf the new node and remove the root
        // Case 3: two leaves, find the greatest left subtree and let it replace
        if ( !root->left && !root->right ) {
            free(root);
            return NULL;
        }
        else if ( root->left == NULL ) {
            Node* temp = root;
            root = root->right; // remove current node
            free(temp);
            return root;
        }
        else if ( root->right == NULL ) {
            Node *temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        else { // two leaves case
            Node *temp = getMax(root->left);
            root->val = temp->val;
            root->left = delete(root->left, temp->val); // REVIEW THIS LINE OF CODE AND REVIEW THIS CASE
        }
    }
    return root;
}

int find(Node* root, int value){
    if ( !root ) 
        return 0;
    else if ( value > root->val ) 
        return find(root->right, value);
    else if ( value < root->val )
        return find(root->left, value);
    else if ( value == root->val )
        return 1;
    else 
        return 0;
}

// NOTE: height represents the LONGEST PATH FROM ROOT TO LEAF
int height(Node* root){
    if ( !root ) { return 0; }
    else {
        int right_h = height(root->right);
        int left_h = height (root->left);
        if (right_h > left_h)
            return (right_h + 1);
        else    
            return (left_h + 1);
    }
}

void freeTree(Node* root){
    if ( root != NULL ) {   
        if ( root->left != NULL ) freeTree(root->left);
        if ( root->right != NULL ) freeTree(root->right);
        free(root);
        root = NULL;
    }
}

int main(void){
    Node* root = NULL;

    // Inserting keys into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inOrderT(root);
    printf("\n");
    printf("tree height: %d\n", height(root));
    printf("Max Value in tree: %d\n", getMax(root)->val);

    delete(root, 30);
    delete(root, 60);
    delete(root, 65);
    inOrderT(root);
    printf("\n");
    
    printf("%d \n", find(root, 32));
    printf("%d \n", find(root, 20));
    
    insert(root, 10);
    insert(root, 12);
    insert(root, 13);
    inOrderT(root);
    printf("\n");
    printf("tree height: %d\n", height(root));

    freeTree(root);
    return 0;
}