
// string to integer (atoi)

#include<bits/stdc++.h>
using namespace std;



int str2int(string s){

	
	int begin = 0;

	int len = (int)s.length();
	if(len == 0){
		return 0;
	}

    for( ; begin < len; ++begin){
		
		if(s[begin] != ' '){
			break;
		}
	}
    if(begin == len){
        return 0;
    }

	long long ans = 0;

	int minusFlag = 1;
	if(s[begin] == '-'){
		begin++;
		minusFlag = -1;
	}
	else if(s[begin] == '+'){
		begin++;
	}
	
    int i = begin;
	for( ; i < len; i++){
    
        if(s[i] < '0' or s[i] > '9'){
            return minusFlag*ans;
        }
		int curr = s[i] - '0';
	
		ans = ans*10 + (curr);
		
		//OVERFLOW handiling
		if(-ans <= INT_MIN and minusFlag==-1){
			//cout<<"neg OVERFLOW"<<endl;
			return INT_MIN;
		}
        if(ans >= INT_MAX and minusFlag == 1){
			return INT_MAX;
		}

        
	}
	return minusFlag*ans;
}
int main(){
	string s;
	cin>>s;

	cout<<str2int(s);
}