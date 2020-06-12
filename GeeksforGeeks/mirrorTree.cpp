

#include<bits/stdc++.h>

using namespace std;


void mirror(Node *root) {

	if(root == NULL) {
		return;
	}

	mirror(root->left);
	mirror(root->right);

	Node *tmp = root->left;
	root->left = root->right;
	root->right = tmpl
	
}