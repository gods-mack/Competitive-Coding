


// C++ program to print level order line by line
#include <bits/stdc++.h> 
using namespace std; 

class node { 
public: 
	int data; 
	node *left, *right; 
}; 

// A utility function to create a new Binary Tree node 
node* newNode(int item) 
{ 
	node* temp = new node(); 
	temp->data = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 


node *magic = newNode(112);

int height(node *root) {

	if(root == NULL) {
		return 0;
	}

	int l = height(root->left);
	int r = height(root->right);

	if(l > r) {
		return 1 + l;
	}
	else{
		return 1 + r;
	}
}



// logic function
void linebyline(node *root) {
	
	
	if(root == NULL) {
		return;
	}
	queue<node*> q;
	q.push(root);

	while(!q.empty()){

		int size = q.size();

		while(size > 0) {
			node *curr = q.front();
			q.pop();
			if(curr->left)
				q.push(curr->left);
			if(curr->right)
				q.push(curr->right);
			
			cout<<curr->data<<" ";
			size--;
		}
		cout<<endl;
	}
}


// Driver code 
int main() 
{ 
	node* root = newNode(12); 
	root->left = newNode(10); 
	root->right = newNode(30); 
	root->right->left = newNode(25); 
	root->right->right = newNode(40); 

	linebyline(root); 


	return 0; 
} 

// This code is contributed by rathbhupendra 
