// A hashmap based C++ program to clone a binary 
// tree with random pointers 
#include<iostream> 
#include<unordered_map> 
using namespace std; 

/* A binary tree node has data, pointer to left child, 
	a pointer to right child and a pointer to 
	random node*/
struct Node 
{ 
	int key; 
	struct Node* left, *right, *random; 
}; 

/* Helper function that allocates a new Node with the 
given data and NULL left, right and random pointers. */
Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->random = temp->right = temp->left = NULL; 
	return (temp); 
} 

/* Given a binary tree, print its Nodes in inorder*/
void printInorder(Node* node) 
{ 
	if (node == NULL) 
		return; 

	/* First recur on left sutree */
	printInorder(node->left); 

	/* then print data of Node and its random */
	cout << "[" << node->key << " "; 
	if (node->random == NULL) 
		cout << "NULL], "; 
	else
		cout << node->random->key << "], "; 

	/* now recur on right subtree */
	printInorder(node->right); 
} 

// This function creates clone by copying key and left and right pointers 
// This function also stores mapping from given tree node to clone. 
// This function copies random node by using the hashmap built by 
// copyLeftRightNode() 

// This function makes the clone of given tree. It mainly uses 
// copyLeftRightNode() and copyRandom() 


void copyRandom(Node *root,map<Node*,Node*> &rmap) {
	if(root == NULL){
		return;
	}
	
	//root->random = rmap[root]->
	rmap[root]->random = root->random;
	rmap[root]->left->random =  copyRandom(root->left,rmap);

	rmap[root]->right->random = copyRandom(root->right,rmap);
	

}

void copyotherNode(Node *root,map<Node*,Node*> &rmap) {

		if(root == NULL){
			return NULL;
		}

		Node *clone = newNode(root->key);

		rmap[root] = clone;

		clone->left = copyotherNode(root->left,rmap);
		clone->right = copyotherNode(root->right,rmap);

		return clone; 

}

Node* cloneTree(Node *root) {
	Node *nr = NULL;

	map<Node*,Node*> rmap;
	pre(root,rmap);




}

/* Driver program to test above functions*/
int main() 
{ 
	//Test No 1 
	Node *tree = newNode(1); 
	tree->left = newNode(2); 
	tree->right = newNode(3); 
	tree->left->left = newNode(4); 
	tree->left->right = newNode(5); 
	tree->random = tree->left->right; 
	tree->left->left->random = tree; 
	tree->left->right->random = tree->right; 

	// Test No 2 
	// tree = NULL; 

	// Test No 3 
	// tree = newNode(1); 

	// Test No 4 
	/* tree = newNode(1); 
		tree->left = newNode(2); 
		tree->right = newNode(3); 
		tree->random = tree->right; 
		tree->left->random = tree; 
	*/

	cout << "Inorder traversal of original binary tree is: \n"; 
	printInorder(tree); 

	Node *clone = cloneTree(tree); 

	cout << "\n\nInorder traversal of cloned binary tree is: \n"; 
	printInorder(clone); 

	return 0; 
} 
