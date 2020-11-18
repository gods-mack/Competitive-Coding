
#include<bits/stdc++.h>
using namespace std;

stack<int> a,b;


void push_f(int x){

	if(a.empty() and b.empty()){
		a.push(x);
	}
	else{
		while(!b.empty()){
			a.push(b.top());
			b.pop();
		}
		a.push(x);
		while(!a.empty()){
			b.push(a.top());
			a.pop();
		}
	}
}

void pop_f(){
	cout<<"poped "<<b.top()<<endl;
	b.pop();	
}

int main() {
	

	push_f(13);
	push_f(34);
	push_f(55);
	push_f(45);
	pop_f();
	push_f(73);
	pop_f();

}