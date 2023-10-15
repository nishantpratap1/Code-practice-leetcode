#include<bits/stdc++.h>
using namespace std;

struct Node {
int data;
struct Node* left;
struct Node* right;
    // A constructor to the struct node
    // that inserts value in the data variable.
    Node(int value)
    {
    data = value;
    left = NULL;//Left child is initialized to NULL
    right = NULL;//Right child is initialized to NULL
    }

}; // defined struct for the tree node for binary tree

Node* LCA(Node* root,Node* p,Node* q){
    if(root == NULL){
        return NULL;
    }
    Node* leftans= NULL;
    Node* rightans= NULL;
    
    if(root->data == p->data || root->data == q->data){
            return root;
     }
    leftans  =  LCA(root->left,p,q);
    rightans =  LCA(root->right,p,q);
    if(leftans !=NULL && rightans != NULL){
            return root;
    }
    
    if(leftans!=NULL) return leftans;
        else return rightans;
}


int main(){
    // taking input of the tree for the LCA (lowest common ancestor) of a Binary tree
    /*
    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    Output: 3
     if   p = 6, q = 2
    Explanation: The LCA of nodes 5 and 1 is 3. */
    /*    3                          1 
        /  \             or         / \   
       5     1                     2    3
      / \   / \                   / \  / \
     6   2  0  8                 4  5  6 7
        / \
       7   4
    */
    
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    
    Node* p = root->left->left;
    Node* q = root->left->right;
    
    Node* res = LCA(root,p,q);
    if(res == NULL){
        return -1;
    }
    cout << " lowest common ancestor of p,q where p,q equals to   "<< p->data << " , "<< q->data <<endl;
    cout << "LCA is  ="<< res->data << endl;
    
    return 0;
    
}
