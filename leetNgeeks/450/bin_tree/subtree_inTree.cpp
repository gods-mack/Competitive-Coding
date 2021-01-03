

// Duplicate subtree in Binary Tree 

//https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1#

unordered_map<string,int> umap;

string util(Node *root) {
	
	if(root == nullptr){
		return "";
	}
	
	string s = "";
	s += util(root->left) + to_string(root->data) + util(root->right);
		
	umap[s]++;
	return s;
}

bool dupSub(Node *root){

	
	string tmp = util(root);

	for(auto it=umap.begin(); it!=umap.end(); ++it) {
		if(it->second > 1 and it->first.length() > 2) {
			return true;
		}
	}
	
	return false;
}