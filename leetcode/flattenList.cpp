



// Given a binary tree, flatten it to a linked list in-place.

// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
#include<bits/stdc++.h>
using namespace std;


struct Node{
	int data;
	Node *left;
	Node *right;
	Node(int x){
		data  = x;
		left = nullptr; right = nullptr;
	}
};

Node *Root = nullptr;



Node* bUtil(Node *root, int x){
	if(root == nullptr){
		Node *newnode = new Node(x);
		return newnode;
	}
	else{
		if(root->data > x){
			//Node* newnode = new Node(x);
			root->left = bUtil(root->left,x);
		}
		if(root->data < x){
			root->right = bUtil(root->right,x);
		}
	}

	return root;
}




void flatten(Node *root){
	
	if(root == nullptr){
		return ;
	}

	stack<Node*> st;
	st.push(root);

	while(!st.empty()){

		Node *curr = st.top();
		st.pop();

		if(curr->right != nullptr)
			st.push(curr->right);

		if(curr->left != nullptr)
			st.push(curr->left);

		if(!st.empty()){
			curr->right = st.top();
		}
		curr->left = nullptr;
	}

}

int main(){
	int n; cin>>n;
	vector<int> lvl(n);
	for(int i = 0; i < n; i++){
		int x; cin>>x;
		Root = bUtil(Root,x);
	}

	//cout<<"rt "<<Root->data<<endl;
	//preorder(Root);
	flatten(Root);	


}