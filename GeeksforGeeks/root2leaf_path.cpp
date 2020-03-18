
// https://practice.geeksforgeeks.org/problems/root-to-leaf-paths/1

/*

Given a Binary Tree of size N, your task is to complete the 
function printPaths() that prints all the possible paths from 
root node to the all the leaf node's of the binary tree.

 */

#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    //struct Node* next;
   

    Node(int x) {
        data = x;
        left = right = NULL;
        //next = nullptr;
    }
};


Node* buildTree(Node *root, int x){
	if(root==NULL){
		Node *newnode = new Node(x);
		return newnode;
	}
	else{
		if(root->data > x){
			root->left = buildTree(root->left,x);
		}
		if(root->data < x){
			root->right = buildTree(root->right,x);
		}
	}
	return root;
}

void root2leafpath(vector<int> &ans, Node *root,int ind){
	if(root == nullptr){
	//	cout<<endl;
		return;
	}
	ans[ind] = root->data;
	ind++;
	if(!root->left && !root->right){
		for(int i = 0; i < ind; i++){
			cout<<ans[i]<<" ";
		}
		cout<<"#";
	}
	else{
		root2leafpath(ans, root->left, ind);
		root2leafpath(ans, root->right,ind);
	}
	
	
}
	

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Node *root = nullptr;
       for (int i = 0; i < n; i++){
        	int x; cin>>x;
       		root = buildTree(root,x);
       	}
       	
       	vector<int> ans(1000,0);
       	
		root2leafpath(ans,root,0);

    }
    return 0;
}


