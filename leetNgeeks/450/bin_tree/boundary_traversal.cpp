
// https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#
//   Boundary Traversal of binary tree 

void leafNodes( Node *root){

	if(root == NULL){
		return;
	}

	leafNodes(root->left);

	if(root->left ==NULL and root->right==NULL){
		cout<<root->data<<" ";
	}

	leafNodes(root->right);
	
}

void leftSide(Node *root){

	if(root == NULL){
		return;
	}
	if(root->left){
		cout<<root->data<<" ";
		leftSide(root->left);
	}
	else if(root->right){
		cout<<root->data<<" ";
		leftSide(root->right);
	}

}

void rightSide(Node *root){

	if(root == NULL){
		return;
	}
	if(root->right){
		rightSide(root->right);
		cout<<root->data<<" ";
	}
	else if(root->left){
		rightSide(root->left);
		cout<<root->data<<" ";
	}

}


void printBoundary(Node *root){

	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	leftSide(root->left);

	leafNodes(root);

	rightSide(root->right);

}
