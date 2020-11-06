#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* new_node(int data){

    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
};

void inorder(struct node* node){

    if(node== NULL)
        return;
    inorder(node->left);
    printf("%d->", node->data);
    inorder(node->right);
}

struct node* insert(struct node* node, int data){

    if(node== NULL)
        return new_node(data);
    if(data<node->data)
        node->left = insert(node->left, data);
    else if(data>node->data)
        node->right = insert(node->right, data);
    return node;
};

int main(){

    struct node* root = NULL;
    root = insert(root,60);
    insert(root,40);
    insert(root,30);
    insert(root,65);
    insert(root,11);

    printf("\n BST tree traversal is -   ");
    inorder(root);
    return 0;
}
