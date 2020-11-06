#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};

struct node* new_node(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->right = NULL;
    node->left = NULL;
    return(node);
};

void inorder(struct node* node){

    if(node== NULL)
        return;
    inorder(node->left);
    printf("%d->", node->data);
    inorder(node->right);
}

void postorder(struct node* node){
    if(node== NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d->", node->data);
}

void preorder(struct node* node){
    if(node== NULL)
        return;
    printf("%d->", node->data);
    preorder(node->left);
    preorder(node->right);
}

int main(){

    struct node* root = new_node(1);
    root->right = new_node(2);
    root->left = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);

    printf("\n Inorder traversal is -    ");
    inorder(root);
    printf("\n Postorder traversal is -    ");
    postorder(root);
    printf("\n Inorder traversal is -    ");
    inorder(root);
    return 0;
}
