#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

node *root;

class bst{

public:
	node* createNode(int data){
		node *n = new node;
		n->data = data;
		n->left = NULL;
		n->right = NULL;
		return n;
	}

	void insertData(int data,node *tmp){
		if(root==NULL){
			root = createNode(data);
		}
		else if (data < tmp->data){

			if(tmp->left!=NULL){
				insertData(data,tmp->left);
			}
			else{
				tmp->left = createNode(data);
			}
		}

		else if (data > tmp->data){

			if(tmp->right!=NULL){
				insertData(data,tmp->right);
			}
			else{
				tmp->right = createNode(data);
			}
		}

		else{
			printf("This is already inserted! ");
		}

	}

	int LCA(int n1,int n2){
		node *tmp = root;

		while(1){

			if( (n1>tmp->data and n2<tmp->data) or (n1<tmp->data and n2>tmp->data)){
				return tmp->data;
			}
			if(n1 < tmp->data){
				tmp = tmp->left;

			}
			else{
				tmp = tmp->right;
			}

		}
	}


};



int main(){
	bst ob;
	ob.insertData(10,root);
	ob.insertData(30,root);
	ob.insertData(-10,root);
	ob.insertData(8,root);
	ob.insertData(9,root);
	ob.insertData(25,root);
	ob.insertData(60,root);
	ob.insertData(78,root);
	ob.insertData(28,root);
	ob.insertData(6,root);

	cout<<ob.LCA(30,78)<<endl;




}