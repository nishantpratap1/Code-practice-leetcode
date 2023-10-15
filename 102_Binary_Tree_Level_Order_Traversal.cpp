#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 */
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

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> res;
    if (root == NULL) {
        return res;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        vector<int> level; // Create a vector for the current level
        int levelSize = q.size(); // Get the size of the current level
        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front(); // curr=9
            q.pop();
            level.push_back(curr->data); // level =  9
            if (curr->left != NULL) {
                q.push(curr->left); // q = 9
            }
            if (curr->right != NULL) {
                q.push(curr->right); // q = 9 20
            }
        }
        res.push_back(level); // Add the level to the result
    }
    return res;
}

int main() {
    // Input: root = [3,9,20,null,null,15,7]
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    vector<vector<int>> result = levelOrder(root);

    // Output: [[3],[9,20],[15,7]]
    for (const vector<int>& level : result) {
        cout << "[";
        for (int i = 0; i < level.size(); i++) {
            cout << level[i];
            if (i < level.size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
    }

    return 0;
}
