

// https://leetcode.com/problems/reconstruct-itinerary/

#include<bits/stdc++.h>
using namespace std;


void findItinerary(vector<vector<string>>& tickets) {

	    unordered_map<string,multiset<string> >  hs;
        
        for(int i=0; i<tickets.size(); i++) {

            hs[tickets[i][0]].insert(tickets[i][1]);
        }
        
        stack<string> st;
        vector<string> ans;
        
        st.push("JFK");
        
        while(!st.empty()) {
            
            string u = st.top();
            
            if(hs[u].size() == 0) {

                ans.push_back(u);
                st.pop();
            }
            else{
                auto dest = hs[u].begin();
                st.push(*dest);
               // cout<<"stacked: "<<*dest<<endl; 
                hs[u].erase(dest);
            }
        }
        reverse(ans.begin(),ans.end());
        for(auto x:ans){
        	cout<<x<<" ";
        }
        
        
}
int main() {

	int n; cin>>n;
	vector<vector<string>> tickets(n);

	for(int i = 0; i < n; i++) {
		string x,y;
		cin>>x>>y;
		tickets[i].push_back(x);
		tickets[i].push_back(y);
	}
	findItinerary(tickets);

}