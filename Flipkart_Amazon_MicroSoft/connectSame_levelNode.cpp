/*
URL : https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1

n a binary tree, connect the nodes that are at same level.
Structure of the given Binary Tree node is like following.


Initially, all the nextRight pointers point to garbage values. 
Your function should set these pointers to point next right for each node.
       10                       10 ------> NULL
      / \                       /      \
     3   5       =>     3 ------> 5 --------> NULL
    / \     \               /  \           \
   4   1   2          4 --> 1 -----> 2 -------> NULL
   
   */



#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    Node* right;
    Node* left;
    Node *nextRight;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
        nextRight = NULL;
    }
};
/* Returns true if the given tree is a binary search tree
 (efficient version). */

/* Driver program to test size function*/
void printSpecial(Node *root)
{
   if (root == NULL)
     return;
   Node *node = root;
   while (node != NULL)
   {
      printf("%d ", node->data);
      node = node->nextRight;
   }
   if (root->left)
     printSpecial(root->left);
   else
     printSpecial(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


void printNextRight(Node*);
int getHeight(Node*);
void connect(Node*);

int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     connect(root);
    //printNextRight(root);
     printSpecial(root);
     cout<<"\n";	
     inorder(root);
     cout<<" ";
  }
  return 0;

} //end of main



//  solution starts from here



int getHeight(Node *tmp){
		
		if(tmp==nullptr){
			return 0;
		}
		int leftTree = getHeight(tmp->left);
		int rightTree = getHeight(tmp->right);
		if(leftTree > rightTree){
			return leftTree + 1;
		}
		else{
			return rightTree + 1;
		}
	}  // end of height func
		
			
	void connect(Node *tmp){
		queue<Node*> queue;
		queue.push(tmp);
		int height  = getHeight(tmp);
		//cout<<"heigth "<<height<<endl;
		for(int i = 0;i < height; i++){
			const int  qsize = queue.size();   // make it const so it cant be change during new push value
			//cout<<"q size "<<qsize<<endl;
			for(int j = 0; j< qsize; j++){
				
				Node* temp = queue.front();
				if(temp->left!=nullptr){
					queue.push(temp->left);
				}
				if(temp->right!=nullptr){
					queue.push(temp->right);
				}
				queue.pop();
				if(j==qsize-1)  // point level's last node to NULL
					temp->nextRight = nullptr;
				else	
					temp->nextRight = queue.front();
				
			}
                        // to check element in queue
			/*q2 = queue;
			while(!q2.empty()){
				auto *print = q2.front();
				cout<<print->data<<" " ;
				q2.pop();
			}
			cout<<endl;*/
		}
		
				
			
	} // end of connect
