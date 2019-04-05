// There are two singly linked lists in a system. 
// By some programming error the end node of one of the linked list 
// got linked into the second list, forming a inverted Y shaped list. 
// Write a program to get the point where two linked lists merge.

/*  10         4
     \       /
      20    5 
        \  /
         30
           \
            43

    here 30 is intersect point
*/

/* INPut
   first Line : Test Case
   Second LIne : x,y,z
   next lines  :  elements

First line is number of test cases. Every test case has four lines. 
First line of every test case contains three numbers, 
X =  (number of nodes before merge point in 1st list), 
y = (number of nodes before merge point in 11nd list) and 
z = (number of nodes after merge point).  Next three lines contain x, y and z values.


// question URL  https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1


#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};


void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}


/* Approach :
 Here's a simple trick. As the values are always positive, so traverse 
 through the first linked list, and multiply all values by -1.
 Now start traversing from the second head. 
 If any negative value is encountered, 
 means that is the merge point. So return negative of that value.
*/
void intersection_point(Node *head1,Node *head2){
     
  Node *tmp1,*tmp2;
  tmp1 = head1; tmp2= head2;
  
  while(tmp1!=NULL){ 
     tmp1->data = (tmp1->data)*(-1);
     tmp1 = tmp1->next; 
  }
 
 while(tmp2!=NULL){
     
   if(tmp2->data<0){
     cout<<" Intersect Point "<<abs(tmp2->data);
     break;
   }
  tmp2 = tmp2->next;
 }
     
 }

/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;
    cin>>T;
    for(int j=0;j<T;j++)
    {
        cin>>n1>>n2>>n3;
        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }
        if (tail1 != NULL)
         tail1->next = head3;
        if (tail2 != NULL)
         tail2->next = head3;
        intersection_point(head1, head2);
    }
    return 0;
}

