#include <bits/stdc++.h>
using namespace std;

struct Node {
	char val;
	vector<Node*> children;
};

// Utility function to create a new tree node
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->val = key;
	return temp;
}

// Function for level order traversal for n-array tree
vector<vector<int> > levelOrder(Node* root)
{
	vector<vector<int> > ans;
	if (!root)
		cout << "N-Ary tree does not any nodes";

	// Create a queue namely main_queue
	queue<Node*> main_queue;

	// Push the root value in the main_queue
	main_queue.push(root);

	// Create a temp vector to store the all the node values
	// present at a particular level
	vector<int> temp;

	// Run a while loop until the main_queue is empty
	while (!main_queue.empty()) {

		// Get the front of the main_queue
		int n = main_queue.size();

		// Iterate through the current level
		for (int i = 0; i < n; i++) {
			Node* cur = main_queue.front();
			main_queue.pop();
			temp.push_back(cur->val);
			for (auto u : cur->children)
				main_queue.push(u);
		}
		ans.push_back(temp);
		temp.clear();
	}
	return ans;
}

// Driver code
int main()
{
	Node* root = newNode(1);
	root->children.push_back(newNode(3));
	root->children.push_back(newNode(2));
	root->children.push_back(newNode(4));
	root->children[0]->children.push_back(newNode(5));
	root->children[0]->children.push_back(newNode(6));

	// LevelOrderTraversal obj;
	vector<vector<int> > ans = levelOrder(root);
	for (auto v : ans) {
		for (int x : v)
			cout << x << " ";
		cout << endl;
	}
	return 0;
}
