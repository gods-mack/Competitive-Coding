/* We will delete duplicate node in Sorted Linked List */

#include<iostream>
using namespace std;

struct node
{
 int data;
 node *next;
};

class List
{
 node *h,*t;
public:
List() { h=NULL,t=NULL; }
float size=0;int mc=1;
node *m;
void add(int x)
{ 
node *n=new node;
if(h==NULL)
{  n->data=x;
  h=n; t=n; m=n;
}
else
{
 n->data=x;
  t->next=n;
  t=n;
}
size++;

}


void deleteDupli()
{
node *prv,*police;
prv=NULL; police=h; 


while(police->next!=NULL)
{
  if(police->data==(police->next)->data)
  {
   if(prv==NULL)
    { 
       h=h->next;
        police=police->next;
        //prv=police;
     }
   else
     { police=police->next;
       prv->next=police;
       
      } 
   }
   else
   { prv=police; 
    police=police->next;
   }

}
}
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

};

int main()
{
 List a;
a.add(2);
a.add(2);
a.add(2);
a.add(2);
a.add(5);

a.add(10);
a.add(10);
a.add(10);
a.add(10);
a.add(10);
a.add(10);
a.add(10);
a.add(11);
a.add(12);
a.add(19);
a.add(20);
a.add(20);
a.add(21);
a.add(21);
a.add(21);
a.add(21);



a.deleteDupli();
a.print();

}


   







