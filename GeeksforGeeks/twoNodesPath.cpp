// C++ program to print left 
// view of Binary Tree 
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

bool LCAUtil(node *root,int a,vector<node*>& path){

	if(!root){
		return false;
	}
	path.push_back(root);

	if(root->data==a){
		return true;
	}

	if(LCAUtil(root->left,a,path)||LCAUtil(root->right,a,path)){
		return true;
	}
	path.pop_back();

	return false;

}


void LCA(node *root,int a,int b) {

	vector<node*> path1,path2;
	if(LCAUtil(root,a,path1)){}
	if(LCAUtil(root,b,path2)){}

	node *lcaNode;
	cout<<"path\n";
	
	for(int i = 0; i < path1.size(); i++) {
		cout<<path1[i]->data<<" ";

	}

	int i = 0;
	while(i < path1.size() && i < path2.size()) {
		if(path1[i] != path2[i]){
			lcaNode = path1[i-1];
			break;
		}
		i++;
	}


	//cout<<"lca "<<lcaNode->data<<endl;

	vector<node*> tmp1;
	vector<node*> tmp2;
	if(LCAUtil(lcaNode->left,a,tmp1));
	if(LCAUtil(lcaNode,b,tmp2)) {}


	cout<<"tmp path1\n";
	for(int i = 0; i < tmp1.size(); i++) {
		cout<<tmp1[tmp1.size()-i-1	]->data<<" ";

	}
	cout<<"\ntmp path2\n";
	for(int i = 0; i < tmp2.size(); i++) {
		cout<<tmp2[i]->data<<" ";

	}


}




void path(node *root,int n1,int n2) {

}

// Driver code 
int main() 
{ 
	node* root = newNode(12); 
	root->left = newNode(10); 
	root->right = newNode(30); 
	root->left->left = newNode(13);
	root->left->left->left = newNode(18);
	root->left->left->right = newNode(98);
	root->right->left = newNode(25);
 	root->right->right = newNode(40); 

		
	LCA(root,98,40);

	

	return 0; 
} 

