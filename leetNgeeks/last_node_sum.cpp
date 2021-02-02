// Code to find the sum of the nodes 
// which are present at the maximum depth. 
#include <bits/stdc++.h> 

using namespace std; 

int sum = 0, max_level = INT_MIN; 
int high  = 0;

struct Node 
{ 
	int d; 
	Node *l; 
	Node *r; 
}; 

// Function to return a new node 
Node* createNode(int d) 
{ 
	Node *node; 
	node = new Node; 
	node->d = d; 
	node->l = NULL; 
	node->r = NULL; 
	return node; 
} 

// Function to find the sum of the node 
// which are present at the maximum depth. 
// While traversing the nodes compare the level 
// of the node with max_level 
// (Maximum level till the current node). 
// If the current level exceeds the maximum level, 
// update the max_level as current level. 
// If the max level and current level are same, 
// add the root data to current sum. 

int height(Node *root) {

	if(root == nullptr) {
		return 0;
	}
	int l = height(root->l);
	int r = height(root->r);

	if(l > r) 
		return l + 1;
	else
		return r + 1;

}

void sumOfNodesAtMaxDepth(Node *root, int level) {

	if(root == nullptr){
		return;
	}
	if( level > max_level) {
		sum = root->d;
		max_level = level;
	}
	else if( level == max_level) {
		sum += root->d;
	}

	sumOfNodesAtMaxDepth(root->l,level+1);
	sumOfNodesAtMaxDepth(root->r,level+1);

	//if(high-1 == level)	sum += root->d; // solution 1
	
}
// Driver Code 
int main() 
{ 
	Node *root; 
	root = createNode(1); 
	root->l = createNode(2); 
	root->r = createNode(3); 
	root->l->l = createNode(4); 
	root->l->r = createNode(5); 
	root->r->l = createNode(6); 
	root->r->r = createNode(7); 
	root->r->r->l = createNode(92); 
	high = height(root);
	sumOfNodesAtMaxDepth(root, 0); 
	cout << sum<<endl;

	return 0; 
} 
