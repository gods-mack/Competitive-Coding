/*
improve version to find minimum element in Stack:
space complexity : improved in : Avg. case and best case
space complexity : worst case still O(n)

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

	if(minn >= data ){
		minn = data;
		cout<<" min "<<minn<<" data "<<data<<endl; 
		s2.push(minn);
	}

	

}

void POP(){
    
	int tmp1 = s1.top();
	s1.pop();
	int tmp2 = s2.top();
	
	if(tmp1 == tmp2){
	    s2.pop();
	}
}

void printAll(stack<int> &s){
    
    while(!s.empty()){
        int tmp = s.top();
        cout<<tmp<<" ";
        s.pop();
    }
}





int main(){

	pushElement(2);
	pushElement(6);
	pushElement(4);
	pushElement(1);
	pushElement(5);
	pushElement(1);
	

	
 	

	cout<<"minimum Element in stack: "<<minElement();
	cout<<"\n";
	POP();
	POP();
	POP();
	POP();  // after pop what will be the minElement
	cout<<"minimum Element in stack: "<<minElement()<<endl; 


}
