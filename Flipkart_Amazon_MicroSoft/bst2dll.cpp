/* convert a binary tree into doubly linked list */



#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
	float data;
	node *left;
	node *right;
};

struct nodedll{
	int data;
	nodedll *left_dll;
	nodedll *right_dll;
	
};

node *Root=nullptr;
node* headDLL = nullptr;
class Tree{
	public:
	
	node *new_node(float data){
		node *n = new node;
		n->data = data;
		n->left = n->right = nullptr; 
		return n;
	}
	
	void insertData(node *root,float data){
		
		if(Root==nullptr){
			Root = new_node(data);
		}
		else{
			if(data > root->data){
				if(root->right!=nullptr){
					insertData(root->right,data);
				}
				else{
					root->right = new_node(data);
				}
			}
			else{
				if(root->left!=nullptr){
					insertData(root->left,data);
				}
				else{
					root->left = new_node(data);
				}
			}
		}
		
	}
	
	
	//  solution starts from here 
	void bst2dll(node *root,node **head_ref){
		stack<node*> stack;
		node* tmp = root;
		node *prv;
		node *tail;
		
		while(tmp!=nullptr or !stack.empty() ){
		
			while(tmp != nullptr){
				stack.push(tmp);
				tmp = tmp->left;
			}
			tmp = stack.top();
			if(*head_ref == nullptr){
				*head_ref = tmp;
				prv = *head_ref;
				tail = *head_ref;
				
			}
			else{
				prv->right = tmp;
				tail = tmp;
				tail->left = prv;
				prv = tail;
			}
				
			
			stack.pop();
			//cout<<tmp->data<<" ";
			tmp =  tmp->right;
		
		
		}
	}
	
	void printList(node *tmp){
		while(tmp!=nullptr){
			cout<<tmp->data	<<" ";
			tmp = tmp->right;
		}
	}

	
	



	
	
}; // end of class tree

int main(){
	Tree ob;
	/*for(int i = 1; i<10; i++){
		ob.insertData(Root,i);
	}*/
	ob.insertData(Root,10);
	ob.insertData(Root,30);
	ob.insertData(Root,20);
	ob.insertData(Root,6);
	ob.insertData(Root,5);
	ob.insertData(Root,4);
	ob.insertData(Root,6.5);
	ob.insertData(Root,7);
	
	ob.bst2dll(Root,&headDLL);
	ob.printList(headDLL);
	
	
}
		
		

