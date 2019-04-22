/* 100 people standing in a circle in an order 1 to 100. No. 1 has a sword.
He kills   the next person (i.e. No. 2) and gives the sword to the next (i.e. No. 3).
All people do the same until only 1 survives. Who will survive at the last?
 */

#include<iostream>
using namespace std;

struct node
{  int data; 
   node *next;
};

class List
{
   public:
   node *h,*t;
   List() { h=NULL; t=NULL; }
   
   void insert(int data)
 {
     node *n=new node();
     n->data=data;
     if(h==NULL)
     { 
        h=n;t=n;
     }
     
    else
   { 
      t->next=n; 
      t=n;
   }
     
   if(data==100)
   {
      t->next=h;
   }

 }

  void killProcess()
  { 
    kill(h);
  }
 
   void kill(node *root )
  {
     node *crnt=root;
    
     while(1) 
     {
     
  
         crnt->next=crnt->next->next;
    
         crnt=crnt->next;
         root=crnt;
        if(root->next==root->next->next)
        { 
           cout<<root->data<<"  bachh gya sala "<<endl;
           break;
        }
     }
  //cout<<root->data;
 
  } // ending of kill function
  
 void print()
  { 
     node *tmp; 
     tmp=h;
   
     while(tmp!=NULL)
    { 
       cout<<tmp->data<<" ";
       tmp=tmp->next;
    }

 }
 


};  // ending of class


int main()
{
  List a;
  for(int i=1;i<=100;i++)
  {
    a.insert(i);
  }
  
 a.killProcess();
 
  //a.print();


}

















