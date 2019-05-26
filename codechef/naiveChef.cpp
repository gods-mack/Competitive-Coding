/*
The game Chef is going to play in the casino consists of tossing a die with N faces twice.
There is a number written on each face of the die (these numbers are not necessarily distinct).
In order to win, Chef must get the number A on the first toss and the number B

on the second toss of the die.

The excited viewers want to know the probability that Chef will win the game.
Can you help them find that number? Assume that Chef gets each face of the
die with the same probability on each toss and that tosses are mutually independent.

Input:
 --> The first line of the input contains a single integer T denoting the number of test cases. The description of T
test cases follows.
-->  The first line of each test case contains three space-separated integers N
, A and B
.
-->  The second line contains N
space-separated integers x1,x2,…,xN denoting the numbers written on the faces of the die.


Example Input

2
5 1 1
1 1 1 1 1
2 1 1
1 2

Example output:
1.0000000000
0.2500000000



*/



#include<iostream>

using namespace std;

int main() {
	double t,n,a,b,i,q;
	cin>>t;
	while(t--){
	    double countA=0,countB=0;
	    cin>>n>>a>>b;
	    for(i=0;i<n;i++){
	       cin>>q;
	        if(a==q) countA++;
	        if(b==q) countB++;
	    }
	    countA=countA/n;
	    countB=countB/n;
	    cout<<countA*countB<<endl;
	}
	return 0;
}

