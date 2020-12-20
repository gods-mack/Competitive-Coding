

// insert an element in bottom of stack recursively

#include<bits/stdc++.h>
using namespace std;

stack<int> s;


void insert_bottom(int x) {

	if(s.empty()) {
		s.push(x);
	}
	else{

		int tmp = s.top();
		s.pop();
		insert_bottom(x);

		s.push(tmp);
	}
}

int main() {
	s.push(3);
	s.push(6);
	s.push(4);

	insert_bottom(2);

	// print stack
	while(!s.empty()) {
		cout<<s.top()<<endl;
		s.pop();
	}
}