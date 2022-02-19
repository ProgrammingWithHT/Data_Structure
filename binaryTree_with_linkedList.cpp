// Binary Search Tree

#include<iostream>
#include<queue>
#include<list>
#include<stack>
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
        q.pop();
        if(current->left != NULL) q.push(current->left);
        if(current->right != NULL) q.push(current->right);
    }
}

// Level By Level Binary Tree Printing
void levelByLevelPrinting(bstNode* root){
    if(root == NULL) return;
    queue<bstNode*> q1;
    queue<bstNode*> q2;
    q1.push(root);
    while (!q1.empty() || !q2.empty())
    {
        while(!q1.empty()){
            bstNode* current = q1.front();
            cout << current->data << " ";
            q1.pop();
            if(current->left != NULL) q2.push(current->left);
            if(current->right != NULL) q2.push(current->right);
        }
        cout << endl;
        while(!q2.empty()){
            bstNode* current = q2.front();
            cout << current->data << " ";
            q2.pop();
            if(current->left != NULL) q1.push(current->left);
            if(current->right != NULL) q1.push(current->right);
        }
        cout << endl;
    }
}



// Can Be used to check parent have same child element
bool checkParentHaveSameChild(bstNode* root){
    if(root==NULL) return true;
    queue<bstNode*> q1;
    queue<bstNode*> q2;
    q1.push(root);
    bstNode* current = q1.front();
    if(current->left != NULL) q2.push(current->left);
    if(current->right != NULL) q2.push(current->right);
    int a = 2;
    while(!q1.empty() || !q2.empty())
    {
        if(a==2){
            q1.pop();
            a=-1;
        }
        while (!q1.empty())
        {
            bstNode* a1 = q1.front();
            q1.pop();
            if(a1->left != NULL) q2.push(a1->left);
            if(a1->right != NULL) q2.push(a1->right);

            bstNode* a2 = q1.front();
            q1.pop();
            if(a2->left != NULL) q2.push(a2->left);
            if(a2->right != NULL) q2.push(a2->right);

            if(a1->data != a2->data){
                return false;
            }

        }
        while (!q2.empty())
        {
            bstNode* a1 = q2.front();
            q1.pop();
            if(a1->left != NULL) q1.push(a1->left);
            if(a1->right != NULL) q1.push(a1->right);
            
            bstNode* a2 = q2.front();
            q1.pop();
            if(a2->left != NULL) q1.push(a2->left);
            if(a2->right != NULL) q1.push(a2->right);

            if(a1->data != a2->data){
                return false;
            }
        }
    }
    return true;
}


// display data by Depth-first: method by pre-order
void preOrder(bstNode *root){
    if (root == NULL) return;  //worst case: Time O(n), space(n)
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void preOrderIterative(bstNode* root){
    if(root==NULL) return;
    stack<bstNode*> s;
    s.push(root);
    while(!s.empty()){
        bstNode* current = s.top();
        cout << current->data << " ";
        s.pop();
        if(current->right != NULL) s.push(current->right);
        if(current->left != NULL) s.push(current->left);
    }
}

// display data by Depth-first: method by in-order
void inOrder(bstNode *root){
    if(root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void inOrderIterative(bstNode* root){
    if(root == NULL) return;
    stack<bstNode*> s;
    while (true)
    {
        if(root != nullptr){
            s.push(root);
            root = root->left;
        }else {
            if(s.empty()) break;
            root = s.top();
            s.pop();
            cout << root->data << endl;
            root = root->right;
        }
    }
}

void postOrderIterative(bstNode* root){
    if(!root) return;
    stack<bstNode*> s;
    bstNode* current = root;
    while(!s.empty() || current!=nullptr){
        if(current != nullptr){
            s.push(current);
            current = current->left;
        }else {
            bstNode* temp = s.top()->right;
            if(temp == nullptr){
                temp = s.top();
                s.pop();
                cout << temp->data << endl;
                while (!s.empty() && temp == s.top()->right) //rightChild == node->rightChild
                {
                    cout << s.top()->data << endl;
                    s.pop();
                }
                
            }
        }
    }

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

// Check Sum To Leaf root
list<int> list1;
bool rootToLeafSum(bstNode *root,int sum){ 
    if(root == NULL) return false;

    if(root->left == NULL && root->right == NULL){
        if(root->data == sum){
            list1.push_back(sum);
            return true;
        }else {
            return false;
        }
    }

    if(rootToLeafSum(root->left,sum-root->data)){
        list1.push_back(root->data);
        return true;
    }
    if(rootToLeafSum(root->right,sum-root->data)){
        list1.push_back(root->data);
        return true;
    }

    return false; //handle if root to leaf sum not exist

}

// Check given tree is Binary Search Tree or Not
bool isBstTree(bstNode *root,int min,int max){
    if(root == NULL) return true;
    if(root->data <=min || root->data > max) return false;
    return isBstTree(root->left,min,root->data) && isBstTree(root->right,root->data,max);
}

// Invert a Binary Tree
void InvertBinaryTree(bstNode* root){
    if(!root) return;
    swap(root->left->data,root->right->data);
    InvertBinaryTree(root->left);
    InvertBinaryTree(root->right);
}

bool checkSymmetric(bstNode* left,bstNode* right){
    if(left == NULL && right == NULL){
        return true;
    }
    if(left == NULL || right == NULL){
        return false;
    }
    if(left->data != right->data){
        return false;
    }
    bool l = checkSymmetric(left->left,right->right);
    bool r = checkSymmetric(left->right,right->left);
    if(l == true && r == true){
        return true;
    }else {
        return false;
    }
    // return checkSymmetric(left->left, right->right) && checkSymmetric(left->right,right->left);  //we also write this line instead of above condition

}
bool isSymmetric(bstNode* root){
    if(!root) return true;
    return checkSymmetric(root->left,root->right);
}

int main(){
    root = insert(root,15);
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,25);
    root = insert(root,8); 
    root = insert(root,12);


    // levelOrder(root);
    levelByLevelPrinting(root);


    // preOrder(root);cout << endl;
    // preOrderIterative(root);

    // cout << rootToLeafSum(root,33);
    // for (list<int>::iterator it=list1.begin(); it != list1.end(); it++)
    // {
    //     cout << *it << " ";
    // }
    
    // Delete(root,8);

    // preOrder(root);

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

// TOPIC: Binary Search Tree (BST)

// NOTES:
// 0. In BST, a node at max can have two children (Left, Right)
// 1. Binary Search Tree is a binary tree data structure which has the following properties.
//    a. The left subtree of a node 'A' should contain all the nodes with lesser value than 'A'.
//    b. The right subtree of a node 'A' should contain all the nodes with higher value than 'A'.
//    c. The left and right subtree also must be a binary search tree.

// 2. It is like having sorted data in tree.
// 3. In-order to have sorted data in tree, tree should have above three properties.

// BENEFITS:
// 0. Instead of using sorted array if we use BST then complexity of Insert, Delete becomes log(n).
// 1. As it maintains sorted elements you have all advantages of data being sorted.

// COMPLEXITY:
// 1. Search, Insert, Delete Complexity: log2(n)
// 2. Space Complexity: O(n)
