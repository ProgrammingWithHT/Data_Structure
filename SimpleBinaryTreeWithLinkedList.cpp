#include<iostream>
using namespace std ;

// Simple Binary Tree With Linked List

struct binaryTree
{
    int data;
    binaryTree *left,*right;
    binaryTree(int data):data{data},left{nullptr},right{nullptr}{};
};

void print_dfs(binaryTree *root){
    if (root == nullptr){
        return;
    }
    cout << root->data << " ";
    print_dfs(root->left);
    print_dfs(root->right);
}


int main(){
    // Nodes construction
    binaryTree *root = new binaryTree(1);
    binaryTree *left = new binaryTree(2);
    binaryTree *right = new binaryTree(3);
    binaryTree *left_left = new binaryTree(4);
    binaryTree *left_right = new binaryTree(5);
    binaryTree *right_left = new binaryTree(6);
    binaryTree *right_right = new binaryTree(7);

    // connecting nodes
    root->left = left;
    root->right = right;
    left->left = left_left;
    left->right = left_right;
    right->left = right_left;
    right->right = right_right;

    // printing binary tree
    print_dfs(root);

    // Deleting nodes
    delete root;
    delete left;
    delete right;
    delete left_left;
    delete left_right;
    delete right_left;
    delete right_right;

    return 0 ;
}