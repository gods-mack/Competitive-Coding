
#include <bits/stdc++.h>
#include <cstring>
using namespace std;

void swap(char *a,char *b){
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void permutation(char *s,int start, int end){
	
	static int count = 0;
	if(start==end){
		count++;
		cout<<s<<" "<<count<<endl;
	}
	
	for(int j=start; j<=end; j++){
		swap(s+start, s+j);
		permutation(s,start+1,end);
		swap(s+start,s+j); // backtracking
	}
}

int main(){
	char s[] = "ABCD";
	permutation(s,0,strlen(s)-1);
	
}
