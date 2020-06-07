
#include <bits/stdc++.h> 
using namespace std; 

// A tree node 
struct Node { 

	int data; 
	Node *left, *right; 
}; 

// Function to create a new node with the given data 
Node* newNode(int data) 
{ 
	Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 
	return node; 
} 
// An iterative function to do post order 
// traversal of a given binary tree 
void postOrderIterative(Node* root) { 
	 
	printf("postorder: "); 
	stack<Node*> st,sp;
	st.push(root);
	//sp.push(root);

	while(!st.empty()) {

		Node *curr = st.top();
		if(!sp.empty() && st.top() == sp.top()){
			cout<<st.top()->data<<" ";
			st.pop();
			sp.pop();
			continue;
		}



		if(curr->left==NULL&&curr->right==NULL){
			cout<<curr->data<<" ";
			st.pop();
			continue;
		}
		else{
			if(curr->right) {
				st.push(curr->right);
			}
			if(curr->left) {
				st.push(curr->left);
			}
		}
		sp.push(curr);
	}


} 

void preOrderIterative(Node* root) { 


	printf("\nPreOrder: ");
	if(root==NULL){
		return;
	}

	stack<Node*> st;
	st.push(root);

	while(!st.empty()) {

		Node* curr = st.top();
		
		st.pop();

		cout<<curr->data<<" ";

		if(curr->right){
			st.push(curr->right);
		}
		if(curr->left){
			st.push(curr->left);
		}
	}
}

void inorderIterative(Node *root ){
	printf("\ninorder: ");

	if(root==NULL){
		return;
	}

	stack<Node*> st,sp;

	st.push(root);

	while(!st.empty()) {

		Node *curr = st.top();

		if(!sp.empty() && curr == sp.top() ){
			cout<<curr->data<<" ";
			sp.pop();
			st.pop();
			st.push(curr->right);
			continue;
		}

		if(curr->left==NULL&&curr->right==NULL){
			cout<<curr->data<<" ";
			st.pop();
			continue;
		}
		else if(curr->left){
			st.push(curr->left);
		}
		sp.push(curr);
	}

}

// Driver code 
int main() 
{ 
	// Let us construct the tree 
	// shown in above figure 
	Node* root = NULL; 
	root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->left = newNode(6); 
	root->right->right = newNode(7); 

	postOrderIterative(root); 
	preOrderIterative(root);
	inorderIterative(root);

	return 0; 
} 


/*

void postOrderTraversal(node* root)
{
    
}*/
