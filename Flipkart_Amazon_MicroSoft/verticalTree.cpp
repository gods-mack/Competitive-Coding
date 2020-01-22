
// print vertical view of a binary tree
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
	Node(int x){
		data = x;
		left = right = nullptr;
	}

};

multimap<int,int> mulmap;

void travel(Node *tmp,int hd){

 if(tmp){
 	mulmap.insert(make_pair(hd,tmp->data));
 	travel(tmp->left,hd-1);
 	travel(tmp->right,hd+1);
 }

}

void verticalOrder(Node *tmpRoot){

	

	if(tmpRoot){
		travel(tmpRoot,0);
	}
	for(auto it=mulmap.begin(); it!=mulmap.end(); ++it){
		cout<<it->second<<" ";
	}
}

int main(){
	int n; cin>>n; // no. of nodes
	map<int,Node*> hash;
	Node *root = nullptr;
	while(n--){
		int n1,n2; char lr;
		Node *parent;

		cin>>n1>>n2; cin>>lr;
		if(hash.find(n1) == hash.end()){
			parent = new Node(n1);
			hash[n1] = parent;
			if(root == nullptr){
				root = parent;
			}
		}
		else{
			parent = hash[n1];
			if(lr == 'L'){
				parent->left = new Node(n2);
				hash[n2] = parent->left;
			}
			else{
				parent->right = new Node(n2);
				hash[n2] = parent->right;
			}

		}
	}
verticalOrder(root);




}