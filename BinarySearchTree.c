#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
    struct node* Node = (struct node*)malloc(sizeof(struct node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}
struct node* insert(struct node* node,int value) {
    if ( node == NULL)
        return newNode(value);
    if ( value < node->data)
        node->left = insert(node->left,value);
    else if ( value > node->data)
        node->right = insert(node->right,value);
    return node;
}
void printInOrder(struct node* node){
    // left -> root -> right;
   if (node == NULL)
       return;
   printInOrder(node->left);
   printf("%d ",node->data);
   printInOrder(node->right);
}
void printPreOrder(struct node* node)
{
   // root -> left -> right;
   if (node == NULL)
       return;
   printf("%d ",node->data);
   printPreOrder(node->left);
   printPreOrder(node->right);
}
void printPostOrder(struct node* node)
{
    // left -> right -> root;
    if (node == NULL)
       return;
   printInOrder(node->left);
   printInOrder(node->right);
   printf("%d ",node->data);
}
int main() {
    struct node* root = NULL;
    root = insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,10);
    insert(root,50);
    insert(root,35);
    printf("Inorder:\n");
    printInOrder(root);
    printf("\nPreorder:\n");
    printPreOrder(root);
    printf("\nPostorder:\n");
    printPostOrder(root);
}
