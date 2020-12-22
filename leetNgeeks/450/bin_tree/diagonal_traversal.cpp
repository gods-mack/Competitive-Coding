// Diagonal Traversal of Binary Tree

// https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/




void diag_traversal_util(Node *root,int d,map<int,vector<int>> mp) {


	if(root == nullptr) {
		return;
	}

	mp[d].push_back(root->data);

	diag_traversal_util(root->left,d+1,mp); // incresase vertical distance left side 


	diag_traversal_util(root->right,d,mp); // right side 'd' will be same or slope same

}


void diag_traversal(Node *root) {

	vector<int> ans;
	if(root == nullptr) {
		return;
	}


	map<int,vector<int>> mp;

	diag_traversal_util(root,0,mp);


}