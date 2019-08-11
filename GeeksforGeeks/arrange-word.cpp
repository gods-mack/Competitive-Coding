/*
We are given an array of strings, we need to sort the array in increasing order of string lengths.

Examples:

Input : {"GeeksforGeeeks", "I", "from", "am"}
Output : I am from GeeksforGeeks

Input :  {"You", "are", "beautiful", "looking"}
Output : You are looking beautiful
*/





#include<bits/stdc++.h>
using namespace std;

bool compare(string &s1,string &s2) 
{ 
    return s1.size() < s2.size(); 
} 

string arrange(string sentence){
	sentence[0] = sentence[0] + 32; // convt. first char into lowercase
    vector<string> tmparray;
    string ans;

    int i  = 0 ;
    string tmp;
    while(sentence[i] != '.'){
        if(sentence[i] == ' '){
            tmparray.push_back(tmp);
            tmp = "";
        }
        else{
        	tmp += sentence[i];
        }
        i++;

    }
    tmparray.push_back(tmp);  // last word 

    sort(tmparray.begin() , tmparray.end(), compare); 
    for(auto x : tmparray){
        for(int i = 0; i < x.length(); i++){
			ans += x[i];
		}
		ans += ' ';
    }

    ans[0] = ans[0] - 32;
    int tlen = ans.length() - 1;
    ans[tlen] = '.';

    return ans;
     


}

int main(){
	string s;
	getline(cin,s);
	string res   = arrange(s);
	cout<<res<<endl;
}
