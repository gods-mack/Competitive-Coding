/*
  Sorted Array to Balanced BST
  */

#include<iostream>

using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};


node* insertBST(int data){

	node *n = new node;
	n->data = data;
	n->left = nullptr;
	n->right = nullptr;

	return n;
}



// Operation Function
node* array2bst(int a[],int start,int end){

	if(start>end) { return NULL; }

	int mid = (start + end)/2;
    /* Get the middle element and make it root */
	node *root = insertBST(a[mid]);

    /* Recursively construct the left subtree  
    and make it left child of root */
	root->left = array2bst(a,start,mid-1);

	root->right = array2bst(a,mid+1,end);

	return root;




}




void inorder(node *tmp){

	if(tmp->left!=NULL){
		inorder(tmp->left);
	}

	cout<<tmp->data<<" ";

	if(tmp->right!=NULL){
		inorder(tmp->right);
	}
}


int main(){
	int n;  cin>>n;// size of array
	int a[n]; // array in Sorted order
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	node *root = array2bst(a,0,n-1);

	// inorder

	inorder(root);



}