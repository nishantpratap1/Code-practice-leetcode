#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
    Node(int value)
    {
    data = value;
    left = NULL;//Left child is initialized to NULL
    right = NULL;//Right child is initialized to NULL
    parent = NULL; // parent initialized to NULL 
    }
};

Node* lowestCommonAncestor(Node* p, Node* q) {
    set<Node*> ancestors;
    ancestors.insert(p);
        // 1. create a set - first add p , if p has parent , add that parent until you reach NULL ( only root element has null parent )
       //2. is q is in the set  or not , if yes return q , if not keep on looking to q parent and keep on checking with set element , the moment you find that you return , else if you dont find you just return no LCA 
    while (p->parent != NULL) {
        p = p->parent;
        ancestors.insert(p);
    }

    while (q != NULL) {
        if (ancestors.count(q) > 0) {
            return q;
        }
        q = q->parent;
    }

    return NULL;
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(5);
    root->left->parent = root;
    root->right = new Node(1);
    root->right->parent = root;
    root->left->left = new Node(6);
    root->left->left->parent = root->left;
    root->left->right = new Node(2);
    root->left->right->parent = root->left;
    root->right->left = new Node(0);
    root->right->left->parent = root->right;
    root->right->right = new Node(8);
    root->right->right->parent = root->right;
    root->left->right->left = new Node(7);
    root->left->right->left->parent = root->left->right;
    root->left->right->right = new Node(4);
    root->left->right->right->parent = root->left->right;

    Node* p = root->left;
    Node* q = root->right;

    Node* lca = lowestCommonAncestor(p, q);

    cout << "Lowest Common Ancestor of nodes " << p->data << " and " << q->data << " is: " << lca->data << endl;

    return 0;
}
