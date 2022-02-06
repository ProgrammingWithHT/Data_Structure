// #include<iostream>
// using namespace std ;

// Simple Binary Tree

// struct binaryTree
// {
//     int data;
//     binaryTree *left,*right;
//     binaryTree(int data):data{data},left{nullptr},right{nullptr}{};
// };

// void print_dfs(binaryTree *root){
//     if (root == nullptr){
//         return;
//     }
//     cout << root->data << " ";
//     print_dfs(root->left);
//     print_dfs(root->right);
// }


// int main(){
//     // Nodes construction
//     binaryTree *root = new binaryTree(1);
//     binaryTree *left = new binaryTree(2);
//     binaryTree *right = new binaryTree(3);
//     binaryTree *left_left = new binaryTree(4);
//     binaryTree *left_right = new binaryTree(5);
//     binaryTree *right_left = new binaryTree(6);
//     binaryTree *right_right = new binaryTree(7);

//     // connecting nodes
//     root->left = left;
//     root->right = right;
//     left->left = left_left;
//     left->right = left_right;
//     right->left = right_left;
//     right->right = right_right;

//     // printing binary tree
//     print_dfs(root);

//     // Deleting nodes
//     delete root;
//     delete left;
//     delete right;
//     delete left_left;
//     delete left_right;
//     delete right_left;
//     delete right_right;

//     return 0 ;
// }

// Binary Search Tree

#include<iostream>
#include<queue>
using namespace std ;


struct bstNode{
    int data;
    bstNode *left;
    bstNode *right;
} *root=NULL;

bstNode* FindMin(bstNode* root);

// add node in empty tree
bstNode* addToEmpty(int data){
    bstNode * temp = new bstNode;
    temp->right = NULL;    
    temp->data = data;
    temp->left = NULL;
    return temp;
}

// insert data in asscending order to binary Search Tree
bstNode* insert(bstNode* root,int data){
    if(root == NULL){
        root = addToEmpty(data);
        return root;
    }else if(data <= root->data){
        root->left = insert(root->left,data);
    }else {
        root->right = insert(root->right,data);
    }
    return root;
}

// search data in binary search tree
bool search(bstNode* root,int data){
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) return search(root->left,data);
    else return search(root->right,data);
}

// Delete data from binary search tree
bstNode *Delete(bstNode* root,int data){
    if(root == NULL){
        return root;
    }
    else if (data < root->data) root->left = Delete(root->left,data);
    else if (data > root->data) root->right = Delete(root->right,data);
    else {
        if (root->left == NULL && root->right == NULL){ //Handle no child
            delete root;
            root = NULL;
        }
        else if (root->left == NULL){ // Handle if right have child
            bstNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL){  //Handle if left Have child 
            bstNode *temp = root;
            root = root->left;
            delete temp;
        }else {
            bstNode* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }
    }
    return root;
}


// Two Method Of Traversal a Binary Tree
// 1. Breath-first
// 2. Depth-first (in depth we have preOrder,inOrderand postOrder Method)

// display data by breath-first
void levelOrder(bstNode* root){
    if(root == NULL) return;
    queue<bstNode*> q;
    q.push(root);
    while(!q.empty()){  //time o(n); and space o(n);
        bstNode * current = q.front();
        cout << current->data << " ";
        if(current->left != NULL) q.push(current->left);
        if(current->right != NULL) q.push(current->right);
        q.pop();
    }
}

// display data by Depth-first: method by pre-order
void preOrder(bstNode *root){
    if (root == NULL) return;  //worst case: Time O(n), space(n)
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
// display data by Depth-first: method by in-order
void inOrder(bstNode *root){
    if(root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
// display data by Depth-first: method by post-order
void postOrder(bstNode *root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

bstNode* FindMin(bstNode* root){
    if(root == NULL){
        cout << "Tree Is Empty";return NULL;
    }else if (root->left == NULL){
        return root;
    }
    return FindMin(root->left);
}


// FindMax of Binary Search Tree With Recursion Method
int FindMax(bstNode* root){                             
    if(root == NULL){                                  
        cout << "Tree Is Empty";return -1;              
    }                                                  
    else if (root->right == NULL){                      
        return root->data;                              
    }                                                   
    return FindMax(root->right);                        
}                      


// Find Sizeof Binary Tree
int getSize(bstNode* root){
    if(root == NULL){
        return 0;
    }
    int leftSize = getSize(root->left);
    int rightSize = getSize(root->right);
    return leftSize + rightSize + 1;
}

// Find height of Binary Tree
int getMaxHeight(bstNode* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = getMaxHeight(root->left);
    int rightHeight = getMaxHeight(root->right);
    return max(leftHeight,rightHeight) + 1;
}

// Check if two BinaryTree is same or not
bool isSameTree(bstNode* root1,bstNode* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    return root1->data == root2->data && isSameTree(root1->left,root2->left) && isSameTree(root1->right,root2->right);
}

int main(){
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,25);
    root = insert(root,8); 
    root = insert(root,12);

    Delete(root,8);

    preOrder(root);

    return 0 ;
}


// bool isSubTreeLesser(bstNode *root, int data);
// bool isSubTreeGreater(bstNode *root, int data){
//     if(root == NULL) return true;
//     if(
//         root->data > data 
//         && isSubTreeGreater(root->left,data) 
//         && isSubTreeGreater(root->right,data)
//     )return true;
//     else return false;
// };
// bool isBinarySearchTree(bstNode *root){
//     if (root == NULL) return 0;
    
//     if(
//         isSubTreeLesser(root->left,root->data) 
//      && isSubTreeGreater(root->right,root->data)
//      && isBinarySearchTree(root->left)
//      && isBinarySearchTree(root->right)
//     )return true;
//     else return false;
// }

// FindMin of Binary Search Tree With Recursion Method
// int FindMin(bstNode* root){
//     if(root == NULL){
//         cout << "Tree Is Empty";return -1;
//     }else if (root->left == NULL){
//         return root->data;
//     }
//     return FindMin(root->left);
// }

// FindMin of Binary Search Tree With Iterative Method
// int FindMax(bstNode* root){
//     bstNode* ptr = root;
//     if(ptr==NULL){
//         cout << "Tree is Empty";return -1;
//     }
//     while (ptr->right != NULL)
//         ptr = ptr->right;

//     return ptr->data;
// }

// FindMin of Binary Search Tree With Iterative Method
// int FindMin(bstNode* root){
//     bstNode* ptr = root;
//     if(ptr==NULL){
//         cout << "Tree is Empty";return -1;
//     }
//     while (ptr->left != NULL)
//         ptr = ptr->left;

//     return ptr->data;
// }
