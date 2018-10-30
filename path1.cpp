//Given an array of N elements and two integers A, B which belongs to the given array. Create a Binary Search Tree by inserting element from arr[0] to arr[n-1]. The task is to find the maximum element in the path from A to B.


#include<iostream>
using namespace std;

struct node
{ 
 double data; 
 node *right,*left;
 };

class BST
{  node *root;
//class BST
public:
 BST() { root=NULL; }
   node* createNode(double x)
   {   node *n=new node();
       n->data=x; 
       n->right=NULL;
       n->left=NULL; 
    return n;
   }
   
   void ins(node *tmp,double x)
   { 
      if(root==NULL)
      { root=createNode(x); }
      else if(tmp->data<x)
      { if(tmp->right==NULL) 
        { tmp->right=createNode(x); }
        else
        { ins(tmp->right,x); }
      }
 
      else if(tmp->data>x)
      { if(tmp->left==NULL) 
        { tmp->left=createNode(x); }
        else
        { ins(tmp->left,x); }
      }

   }
  void addleaf(double  x) 
   { ins(root,x); }


void findNode(node *tmp,double x,double y)
{
   if(x<=tmp->data && y>=tmp->data) 
  {  cout<<" Root  "<<tmp->data; }
  
  if(x<tmp->data && y<tmp->data)
  { findNode(tmp->left,x,y); }
  
  if(x>tmp->data && y>tmp->data)
  { findNode(tmp->right,x,y); }
 
}

void getNode(double x,double y)
{ findNode(root,x,y); }

};

int main()
{
 BST a;   
 a.addleaf(23); // here we are not using array.we direct insert node in BST.But we  
 a.addleaf(43); // could also use array .
 a.addleaf(33);
 a.addleaf(56);
 a.addleaf(17);
 a.addleaf(34); 
 a.addleaf(11); 
 a.addleaf(19);
 a.addleaf(18);
a.addleaf(32);
a.addleaf(29);
a.addleaf(30);
a.addleaf(28.3);
a.addleaf(28.5);
a.addleaf(28.2);


a.getNode(28.5,30);  //input A and B respectively (A>B must be) .

}























