Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};
// Create new node
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
// Search index in inorder
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}
// Build tree
struct node* buildTree(int inorder[], int postorder[], int start, int end, int *postIndex) {
    if (start > end)
        return NULL;
    // Pick current root
    struct node* root = newNode(postorder[*postIndex]);
    (*postIndex)--;
    // If only one element
    if (start == end)
        return root;
    // Find root in inorder
    int index = search(inorder, start, end, root->data);
    // Build right first, then left
    root->right = buildTree(inorder, postorder, index + 1, end, postIndex);
    root->left  = buildTree(inorder, postorder, start, index - 1, postIndex);
    return root;
}
// Preorder traversal
void preorder(struct node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
int main() {
    int n;
    scanf("%d", &n);
    int inorder[n], postorder[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);
    int postIndex = n - 1;
    struct node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);
    preorder(root);
    return 0;
}
