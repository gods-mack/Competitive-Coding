/*
find minimu elemnt in stack..
Time : O(1)
space : O(n);

*/



#include<bits/stdc++.h>
using namespace std;

stack<int> s1;
stack<int> s2;
int minn = 999999999; // very big number


int minElement(){        // O(1)

	return s2.top();

}

void pushElement(int data){

	s1.push(data);

	if(minn > data){
		minn = data;
		//cout<<" min "<<minn<<" data "<<data<<endl; 
		s2.push(minn);
	}
	else{
		s2.push(minn);
	}

}

void POP(){
	s1.pop();
	s2.pop();
}	




int main(){

	pushElement(2);
	pushElement(4);
	pushElement(7);
	pushElement(1);
	pushElement(6);
	pushElement(9);

	

	cout<<"minimum Element in stack: "<<minElement();
	cout<<"\n";
	POP();
	POP();  // after pop what will be the minElement
	cout<<"minimum Element in stack: "<<minElement()<<endl;



}
