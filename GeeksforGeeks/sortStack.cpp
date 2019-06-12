
/*
Sort stack using another temporary stack

*/


#include<iostream>
#include<bits/stdc++.h>

using namespace std;


struct node
{	
	int data;
	node *next;
	
};

node *top1=nullptr,*top2=nullptr;  // top1 - >input stack pointer
                                    // top2  -> temporary stack pointer

class stak{
public:

	void pushStack(node **top,int data){
		node *n = new node;
		n->data = data;
		n->next = *top;
		*top = n;

	}

	void sortStack(){

		while(top1!=NULL){

			int tmp = topElement(top1);
			popStack(&top1);

			while(top2!=NULL and topElement(top2) > tmp){
				pushStack(&top1,topElement(top2));
			    popStack(&top2);
			}


			pushStack(&top2,tmp);
		}
	}
		
	

	void printStack(node *top){

		while(top!=NULL){
			cout<<top->data<<" ";
			top = top->next;
		}
	}

	void popStack(node **top){

		node *tmp = *top;
		*top = (*top)->next;
		delete tmp;
		//return top1->data;

	}

	int topElement(node *top){

		return top->data;
	}

};

int main(){

	stak ob1;
	ob1.pushStack(&top1,9);
	ob1.pushStack(&top1,4);
	ob1.pushStack(&top1,5);
	ob1.pushStack(&top1,3);
	ob1.pushStack(&top1,8);

	//ob1.printStack(top1);

	ob1.sortStack();


	ob1.printStack(top2);



}
















