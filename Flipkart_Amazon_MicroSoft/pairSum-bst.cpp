/*
Given a Binary Search Tree and a target sum, write a function that returns true if
there is a pair with sum equals to target sum, otherwise return false.

*/


#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

std::vector<int> a;

node *Root = nullptr;

node* createNode(int data){
	node *n  = new node;
	n->data = data;
	n->left = nullptr;
	n->right = nullptr;
	return n;
}

node* insertData(node *root, int data){
	if(root == nullptr){
		root = createNode(data);
	}
	if(root->data > data){
		root->left = insertData(root->left,data);
	}
	if(root->data < data){
		root->right = insertData(root->right,data);
	}
	return root;
	
}

void inOrder(node *tmp){
	if(tmp == nullptr){
		return ;
	}
	inOrder(tmp->left);
	//cout<<tmp->data<<" ";
	a.push_back(tmp->data);
	inOrder(tmp->right);
}

bool isPairPresent( node *root, int sum){

	node *tmp = root;
	a.clear();
	inOrder(tmp);
	int i = 0; // first pointer
	int j = a.size() -1 ; // last pointer

	while(i < j){
		if(a[i]+a[j] > sum){
			j = j - 1;
		}
		if(a[i]+a[j] < sum){
			i++;
		}
		if(a[i]+a[j] == sum and a[i] != a[j]){    //  if,a[i]+a[j] == sum not allowed when a[i] == a[j] noth are same
			return 1;
		}
	}
	
	return 0;
}


int main(){
	int T; 
	cin>>T;
	while(T--){
		int n;
		cin>>n; int sum;
		cin>>sum;
		node *root  = nullptr;
		for(int i = 0; i < n; i++){
			int x; cin>>x;
			if(root == nullptr){
				root  = createNode(x);
			}
			else{
				root = insertData(root,x);
			}

     	}
     	//inOrder(root);
     	cout<<isPairPresent(root,sum)<<endl;
     }
}
