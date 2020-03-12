

// Construct BST from its given level order traversal

// https://practice.geeksforgeeks.org/problems/convert-level-order-traversal-to-bst/1
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


void preorder(Node *tmp){
	if(tmp == nullptr ){
		return ;
	}
	cout<<tmp->data << " ";
	preorder(tmp->left);
	preorder(tmp->right);
}

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


Node* buildTree(vector<int> &lvl ){
		
	Node *root = nullptr;
	for(int i = 0; i < lvl.size(); i++){
		root = bUtil(root,lvl[i]);
	}
	return root;
}


int main(){
	int n; cin>>n;
	vector<int> lvl(n);
	for(int i = 0; i < n; i++){
		cin>>lvl[i];
	}

	Node *Root = buildTree(lvl);
	//cout<<"rt "<<Root->data<<endl;
	preorder(Root);	


}