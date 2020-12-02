
// reverse stack using recursion

#include<bits/stdc++.h>
using namespace std;


namespace my {
	int count = 0;
}

void insert_bottom(stack<int>&s,int x) {
	
	if(s.empty()) {
		
		s.push(x);
	}
	else{
	
		int tmp = s.top();
		s.pop();

		insert_bottom(s,x);

		s.push(tmp);
	}
}

void reverse_stack(stack<int>&s) {

	if(!s.empty()) {

		int a = s.top();
		s.pop();
		reverse_stack(s);

		insert_bottom(s,a);
	}
}

int main() {
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	reverse_stack(s);

	// print reversed

	while(!s.empty()) {
		cout<<s.top()<<endl;
		s.pop();	
	}
}