
/* program to find level sum of BST

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;



struct node
{
	int data;
	node *left;
	node *right;
	
};

node *root;
class bstLevelSum
{
public:
    
	node* createNode(int data){
		node *n = new node;
		n->data = data;
		n->left = nullptr;
		n->right = nullptr;
		return n;

	}	

	void insertData(node *tmp,int data){

		if(root==nullptr){
			root = createNode(data);
		}

		else{
			if(tmp->data > data){
				if(tmp->left!=NULL){
					insertData(tmp->left,data);
				}
				else{
					tmp->left = createNode(data);
				}
			}

			else{
				if(tmp->right!=NULL){
					insertData(tmp->right,data);
				}
				else{
					tmp->right = createNode(data);
				}
			}

		}

	}

	int getHeight(node *tmp){

		if(tmp==NULL){
			return 0;
		}
		else{
			int lDepth = getHeight(tmp->left);
			int rDepth = getHeight(tmp->right);

			if(lDepth>rDepth){
				return (1+lDepth);
			}
			
			else{
				return (1+rDepth);
			}
		}


	}

	void getLevelSum(node *root,int height){

		for(int i=1;i<=height;i++){

			int result = levelSum(root,i,0);
			cout<<result<<" sum of Level->"<<i<<endl;
		}
	}

   
   int levelSum(node *tmp,int level,int sum){

   	    

   		if(tmp==nullptr){
   			return sum;
   		}

   		if(level==1){
   			sum = sum+tmp->data;

   		}
   		else if(level>1){

   			sum = levelSum(tmp->left,level-1,sum);
   			sum = levelSum(tmp->right,level-1,sum);
   		}

   		return sum;


   }

	

};



int main(){


	bstLevelSum ob;
	ob.insertData(root,12);
	ob.insertData(root,7);
	ob.insertData(root,16);

	ob.insertData(root,3);
	ob.insertData(root,21);
	ob.insertData(root,14);
	ob.insertData(root,13);
	ob.insertData(root,27);
	ob.insertData(root,25);
	ob.insertData(root,29);

	//for(int i=0;i<bstLevelSum::leftTree.size();i++){
	//	cout<<bstLevelSum::leftTree[i]<<" ";
	//}

	//cout<<bstLevelSum::height;
	int height = ob.getHeight(root);
	
	ob.getLevelSum(root,height);

   
}
