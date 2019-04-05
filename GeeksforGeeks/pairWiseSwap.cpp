/*
Given a singly linked list of size N. The task is to swap elements pairwise

Input:
First line of input contains number of testcases T. For each testcase, 
first line of input contains length of linked list and next line contains linked list data.

Output : 
 print List after swappped

Example :
Input:
1
8
1 2 2 4 5 6 7 8

Output:
2 1 4 2 6 5 8 7


*/

#include<iostream>
using namespace std;

struct node{
 int data;
 node *next;
};

node *head; // make  them global
node *tail; 

void insert(){
    int n;
    cin>>n;
   
   for(int i=0;i<n;i++) { 
     int x; cin>>x;   
      node *nw = new node;   // create a dynamic new node
       if(i == 0){ 
  	 nw->data = x;
     	 tail = nw;
	 head  = nw;
       }
       else{
         nw->data = x;
  	 tail->next = nw;
         tail = nw;
       }
  }
 }

void swap(int *a, int *b){
  	  int ptr;
	  ptr = *b;
	  *b = *a;
	  *a = ptr;
	  
}  // end

 void pairwiseSwap(node *head){
    node *tmp;
    tmp = head;
  
 while(tmp!=NULL){ 
   
   if(tmp->next!=NULL){ 
       swap(tmp->data,tmp->next->data);
        tmp = tmp->next;
   }
    tmp = tmp->next;
     
 }
}  // end func.

void printList(node *head){
  node *tmp;
  tmp =  head;
  while(tmp!=NULL){
   cout<<tmp->data<<" " ;
   tmp = tmp->next;
  }
}  // end

 

int main(){

  int t;
  cin>>t;
  while(t--){
     insert();
     
     pairwiseSwap(head);
     printList(head);
  }
 
}  // end main
  
