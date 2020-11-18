

#include<bits/stdc++.h>
using namespace std;



/*bool isPalin(char *s){

	int n = strlen(s);
	int i = 0;
	int j = n-1;
	while(i <= j ){
		if(s[i]!=s[j]){
			return false;
		}
		i++;
		j--;
	}

	return true;
}



int part(char s[]){

	if(isPalin(s)){
		//cout<<"git here\n";
		return 0;
	}

	return 1 +  part(s+)
}
*/

bool isPalin(string s){

	int n = s.length();
	int i = 0;
	int j = n-1;
	while(i <= j ){
		if(s[i]!=s[j]){
			return false;
		}
		i++;
		j--;
	}

	return true;
}



int part(string s,int i,int j){

	//cout<<"ROOT "<<s<<endl;

	if(i >=j or isPalin(s)){
		//cout<<"git here\n";
		return 0;
	}


	int ans = INT_MAX;

	for(int k = i; k < j; k++) {
		string l_s = "";
		string r_s = "";
		for(int ll = i;ll <= k; ll++){
			l_s += s[ll];
		}
		for(int rr = k+1; rr <= j; rr++) {
			r_s += s[rr];
		}


		int count =  1 + part(l_s,i,k)+ 
						 part(r_s,k+1,j); 

		ans = min(count,ans);

	}


	return ans;
}


int main() {
	//string s;
	//cin>>s;

	//string a = "";
	/*char s[100];
	cin>>s;
	//char tmp[] = "amdj
	if(isPalin(s)){
		cout<<"palin\n";
	}

	char tmp[] = "2djsn";
	if(s == tmp){
		cout<<"equal\n";
	}
	cout<<tmp<<endl;*/

	string s; cin>>s;

	cout<<part(s,0,s.length()-1);
	
	//strcpy(s,a);
	//cout<<a;

}