

// KMP matching algo

#include<bits/stdc++.h>
using namespace std;



void LPS_array(vector<int> &lps,string pat){

	int m = pat.length();

	int len = 0;
	int i = 1;

	while(i < m){

		if(pat[len]==pat[i]){
			lps[i] = len+1;
			len++;
			i++;
		}
		else{
			if(len!=0){
				len = lps[len-1];
			}
			else{
				lps[i]=0;
				i++;
			}
		}
	}

}

void KMP(string text,string pat){

	int n = text.length();
	int m = pat.length();

	vector<int> lps(m,0);

	LPS_array(lps,pat);

	int i = 0;
	int j = 0;

	while(i < n-m+1 ){


		if(text[i]==pat[j]){
			i++;
			j++;
		}
		else{
			if(j!=0){
				j = lps[j-1];
			}
			else{
				i++;
			}
		}
		if(j==m){
			cout<<"found\n";
			j = lps[j-1]; // continue to find more similar pattern
						 // you can break;
		}
	}
}

int main(){
	string text,pat;
	cin>>text>>pat;


	KMP(text,pat);
}