
//  Implement two stacks in an array 

// https://practice.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1#

#include<bits/stdc++.h>
using namespace std;


int n = 100;
int top1 = -1;
int top2 =  n;
int arr[100];



void push1(int x) {

	if(top1 == n/2-1) {
		cout<<"FULL STACK 1\n";
		return;
	}
	top1++;
	arr[top1] = x;
}

void push2(int x) {

	if(top2 == n/2) {
		cout<<"FULL STACK 2\n";
		return ;
	}
	top2--;
	arr[top2] = x;
}

int pop1() {

	if(top1 == -1) {
		cout<<"EMPTY STACK 1\n";
		return -1;
	}
	int x = arr[top1];
	arr[top1] = 0;
	top1--;
	return x;
}

int pop2() {

	if(top2 == n) {
		cout<<"EMPTY STACK 2\n";
		return -1;
	}
	int x = arr[top2];
	arr[top2] = 0;
	top2++;
	return x;
}


int main() {
	



	push2(32);
	push1(233);
	cout<<pop1()<<endl;
	for(int i = 0; i < 100; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;


}