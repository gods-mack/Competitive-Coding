/*

 convert BST to DLL( doubly linked list )

 */



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

	node *prv=NULL,*curr=NULL,*head=NULL;
	
	// main operation function to convert BST to DLL
	void bst2dll(node *curr,node **head){

		if(curr==NULL){
			return;
		}

		static node *prv = NULL;

		bst2dll(curr->left,head);

		if(prv == NULL){
			*head = curr;
		}
		else{
                        curr->left = prv;
			prv->right = curr;

		}
		prv = curr;

		bst2dll(curr->right,head);
	 
		
	}


	void printList(node *tmp){

		while(tmp!=NULL){
			cout<<tmp->data<<" ";
			tmp = tmp->right;
		}
	}


	void inorder(node *tmp){

		if(tmp->left!=NULL){
			inorder(tmp->left);
		}
		cout<<tmp->data<<" ";
		if(tmp->right){
			inorder(tmp->right);
		}
	}

};


int main(){

	bst obj;

	obj.insertData(15,root);
	obj.insertData(12,root);
	obj.insertData(13,root);
	obj.insertData(19,root);
	obj.insertData(17,root);

	cout<<"inorder traversal : " ; 
	obj.inorder(root);
	cout<<endl;

	node *head = NULL;

	obj.bst2dll(root,&head);
        cout<<"DLL : ";
	obj.printList(head);
	

}
