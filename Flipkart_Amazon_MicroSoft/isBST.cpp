/*
Given a binary tree, return true if it is BST, else false. 
*/





#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
/* Returns true if the given tree is a binary search tree
 (efficient version). */
bool isBST(struct Node* node);

/* Driver program to test size function*/
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
     cout << isBST(root) << endl;
  }
  return 0;

} //end of main


vector<int> vec; 
void inOrder(Node *tmp){
	if(!tmp)
		return;
	inOrder(tmp->left);
	vec.push_back(tmp->data);
	inOrder(tmp->right);	
}

bool isBST(Node* root) {
    // Your code here
    vec.clear();
    inOrder(root);
    //a.pop_back();
    for(int i = 1;i<vec.size(); i++){
        if(vec[i-1] > vec[i])
            return false;   //  not BST
    }
    return true;  // its bST
}	

	
