
/*
Find Kth smallest element in BST
*/

#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left;  
	node *right;  
	
};

node *root = NULL;

class bst{
public:

	node* createNode(int data){
		node *n = new node();
		n->data = data;
		n->left = nullptr;
		n->right = nullptr;

		return n;
	}

	void insertData(node *tmp,int data){

		if(root==NULL){

			root = createNode(data);
		}
		else{

			if(data<tmp->data){ // left side

				if(tmp->left!=NULL){
					insertData(tmp->left,data);
				}
				else{
					tmp->left = createNode( data);
				}
			}
			if(data>tmp->data){ // right side
			  
				if(tmp->right!=NULL){
					insertData(tmp->right,data);
				}
				else{
					tmp->right = createNode( data);
				}	

			}


		}

	}
   
	
	int count=0;
	
	// main operation function to fin kth smallest element in bST
	void kthSmall(node *tmp,int k){
        //count++;
		if(tmp->left!=NULL){
			kthSmall(tmp->left,k);
		}
		
		count++;
		if(k==count){
			cout<<"kth small"<<tmp->data<<endl;
		}	
       
		if(tmp->right!=NULL){
			kthSmall(tmp->right,k);
			
		}
		//count++;
		
		
	}




};


int main(){

	bst ob;

	ob.insertData(root,16);
	ob.insertData(root,12);
	ob.insertData(root,10);
	ob.insertData(root,24);
	ob.insertData(root,22);
	ob.insertData(root,34);
	ob.insertData(root,28);
	ob.insertData(root,-10);

	ob.kthSmall(root,7);
	//cout<<ob.getCount()<<endl;
}
