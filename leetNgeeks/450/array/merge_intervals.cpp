


#include<bits/stdc++.h>
using namespace std;

static bool cmp(vector<int> a, vector<int> b) {
        if(a[0] > b[0]) {
            return false;
        }
        else if(a[0] == b[0]){
            if(a[1] > b[1]){
                return false;
            }
         }
        return true;
}

void merge_intervals(vector<vector<int>> &inter) {
	  	int m = inter.size();
        sort(inter.begin(),inter.end(),cmp);
        for(auto p:inter) {
            cout<<p[0]<<" "<<p[1]<<endl;
        }
        

	    vector<vector<int> > ans;
        if(m == 0) {
            return ;
        }
        
        vector<int> tmp(2);
        tmp[0] = inter[0][0];
        tmp[1] = inter[0][1];
        ans.push_back(tmp);
        
        for(int i = 1; i < m; i++) {
            
            if(ans[ans.size()-1][1] >= inter[i][0]  ){
                if( ans[ans.size()-1][1] < inter[i][1])
                    ans[ans.size()-1][1] = inter[i][1];
            }
            else{
                tmp[0] = inter[i][0];
                tmp[1] = inter[i][1];
                if(ans[ans.size()-1]!=tmp)
                    ans.push_back(tmp);
            }
        }

    cout<<"##\n";
	for(auto p:ans) {
		cout<<p[0]<<" "<<p[1]<<endl;
	}
}


int main()  {

	int m; cin>>m;
	vector<vector<int>> inter(m);
	for(auto &p:inter ) {
		int a,b; cin>>a>>b;
		p.push_back(a);
		p.push_back(b);
	}

	merge_intervals(inter);





}
