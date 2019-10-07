// Longest common subsequence using Bottom Up approach

#include<bits/stdc++.h>
using namespace std;




int lcs(string s1, string s2, int m, int n){

	int memo[m+1][n+1];



	for(int i = 0; i <= m; i++){
		for(int j = 0;  j <= n; j++){

			if(i==0 or j==0){
				memo[i][j] = 0;
			}

			else if(s1[i-1] == s2[j-1]){
				memo[i][j] = memo[i-1][j-1] + 1;
			}
			else{
				memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
			}
		}
	}

	// back tracking
	int index = memo[m][n];
	char lcs[index+1];
	lcs[index] = '\0';
	int i = m, j = n; 
   while (i > 0 && j > 0) 
   { 
      // If current character in X[] and Y are same, then 
      // current character is part of LCS 
      if (s1[i-1] == s2[j-1]) 
      { 
          lcs[index-1] = s1[i-1]; // Put current character in result 
          i--; j--; index--;     // reduce values of i, j and index 
      } 
  
      // If not same, then find the larger of two and 
      // go in the direction of larger value 
      else if (memo[i-1][j] > memo[i][j-1]) 
         i--; 
      else
         j--; 
   } 

	
	cout<<lcs;
	cout<<endl;
	return memo[m][n];


}



int main(){
	string s1;
	string s2;
	cin>>s1>>s2;

	cout<<lcs(s1,s2,(int)s1.length(), (int)s2.length())<<endl;
}