
// print the boundry element  of binary tree in anticlockwise


#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


int height(struct Node *root)
{
    if(root==NULL)
        return 0;
    int l = 1+height(root->left);
    int r=1+height(root->right);
    if(l>r)
        return l;
    else
        return r;
}


void leafNodes( Node *root){

	if(root == NULL){
		return;
	}

	leafNodes(root->left);

	if(root->left ==NULL and root->right==NULL){
		cout<<root->data<<" ";
	}

	leafNodes(root->right);
	
}

void leftSide(Node *root){

	if(root == NULL){
		return;
	}
	if(root->left){
		cout<<root->data<<" ";
		leftSide(root->left);
	}
	else if(root->right){
		cout<<root->data<<" ";
		leftSide(root->right);
	}

}

void rightSide(Node *root){

	if(root == NULL){
		return;
	}
	if(root->right){
		rightSide(root->right);
		cout<<root->data<<" ";
	}
	else if(root->left){
		rightSide(root->left);
		cout<<root->data<<" ";
	}

}


void printBoundary(Node *root){

	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	leftSide(root->left);  // print left side

	leafNodes(root->left); // print leafNodes
	leafNodes(root->right);

	rightSide(root->right); // print right side

}

/* Driver program to test above functions*/
int main(){
	int t;
  	scanf("%d", &t);
  	while (t--){
    	map<int, Node*> m;
    	int n;
    	scanf("%d",&n);
     	Node *root = NULL;
     	while (n--){
        	Node *parent;
        	char lr;
        	int n1, n2;
        	scanf("%d %d %c", &n1, &n2, &lr);
      	//  cout << n1 << " " << n2 << " " << (char)lr << endl;
        	if (m.find(n1) == m.end()){
           		parent = new Node(n1);
           		m[n1] = parent;
           		if (root == NULL)
             		root = parent;
        	}
        	else
           		parent = m[n1];
        	Node *child = new Node(n2);
        	if (lr == 'L')
          		parent->left = child;
        	else
          		parent->right = child;
        	m[n2]  = child;
    	}
    	printBoundary(root);
   		cout<<endl;
  	}
    return 0;
}



