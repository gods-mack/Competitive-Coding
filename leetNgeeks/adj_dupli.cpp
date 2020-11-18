

#include<bits/stdc++.h>
using namespace std;


void ps(stack<char> st){
	string s="";

	while(!st.empty())
        {
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
       // n=s.size();
        cout<<s<<endl;

}

void further(string s){

	int n = s.length();
	
	stack<char> st;
	st.push(s[0]);
	char last = s[0];


	for(int i = 1; i < n; i++) {

		if(last==s[i] or st.top()==s[i]){
			st.pop();
			last = s[i];
		}
		else{
			st.push(s[i]);
			last = s[i];
		}
	}
	stack<char> ans;

	while(!st.empty()) {
		//cout<<st.top()<<;
		ans.push(st.top());
		st.pop();
	}

	while(!ans.empty()) {
		cout<<ans.top();
		//ans.push(st.top());
		ans.pop();
	}

	
	//cout<<ans<<endl;
}


void fn(string s,int n)
{
    stack<char> st;
    int flag=1;
    while(flag!=0 && s.size()!=0)
    {
        flag=0;
        int i=0;
        while(i<n)
        {
            if(st.empty() || s[i]!=st.top())
                st.push(s[i]);
            else
            {
            	cout<<"in -> "<<s[i]<<endl;
            	ps(st);
                flag=1;
                while(!st.empty() && st.top()==s[i])
                    i++;
                st.pop();
                st.push(s[i]);
                ps(st);
            }
            i++;
            cout<<"i bn gya "<<i<<endl;
        }
        s="";
        cout<<"yha aayi\n";
        while(!st.empty())
        {
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        n=s.size();
    }
    cout<<s;
}





int main() {
	int t; cin>>t;
	while(t--) {
	string s;
	cin>>s;

	//further(s);
	fn(s,s.length());
	cout<<endl;
}


}