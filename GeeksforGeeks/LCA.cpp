/*

using two arrayList 
*/




#include<iostream>
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

	void LCA(int n1,int n2){

		vector<int> a1;
 		vector<int> a2;

		if( (n1>root->data and n2<root->data) or (n1<root->data and n2>root->data)){
			cout<<root->data<<" is the LCA node. "<<endl;
		}

		else if(n1>=root->data and n2>=root->data){
 			

 			node *tmp = root;
            //tmp = tmp->right;
            a1.push_back(tmp->data);
            //a2.push_back(tmp->data);
 			while(1){

 				if(tmp->data > n1){
 					tmp = tmp->left;
 					a1.push_back(tmp->data);
 				}
 				else{
 					tmp = tmp->right;
 					a1.push_back(tmp->data);
 				}
 				if(tmp->data == n1){
 					break;
 				}
 				

 			}
 			tmp = root;
 			while(1){

 				if(tmp->data > n2){
 					tmp = tmp->left;
 					a2.push_back(tmp->data);
 				}
 				else{
 					tmp = tmp->right;
 					a2.push_back(tmp->data);
 				}
 				if(tmp->data == n2){
 					break;
 				}
 				

 			}
		}

		else if(n1<root->data and n2<root->data){
			node *tmp = root;
            tmp = tmp->left;
            a1.push_back(tmp->data);
          
 			while(1){

 				if(tmp->data > n1){
 					tmp = tmp->left;
 					a1.push_back(tmp->data);
 				}
 				else{
 					tmp = tmp->right;
 					a1.push_back(tmp->data);
 				}
 				if(tmp->data == n1){
 					break;
 				}
 				

 			}
 			tmp = root;
 			while(1){

 				if(tmp->data > n2){
 					tmp = tmp->left;
 					a2.push_back(tmp->data);
 				}
 				else{
 					tmp = tmp->right;
 					a2.push_back(tmp->data);
 				}
 				if(tmp->data == n2){
 					break;
 				}
 				

 			}


		}

		for(int i=0;i<a1.size();i++){
			cout<<a1[i]<<" ";
		}
		cout<<endl;
		for(int j=0;j<a2.size();j++){
			cout<<a2[j]<<" ";
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

	ob.LCA(10,78);

}