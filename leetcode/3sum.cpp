
/*

Given an array nums of n integers, are there elements a, b, c in nums 
such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.


*/

#include<bits/stdc++.h>
using namespace std;

struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};


void tripletSum(vector<int> &a){

	int n = (int)a.size();
	sort(a.begin(),a.end());

	//set<int> hash;
	
	cout<<endl;	

	for(int i = 0; i < n ; i++){
		int aa = a[i];
		unordered_set<int> hash;
		for(int j = i+1; j < n; j++){
			int b = a[j];
			
		
			int c = (aa+b);
			c = -c;
			if(hash.find(c) != hash.end() ){

				cout<<aa<<" "<<b<<" "<<c<<" "<<endl;
			}
			else{
				hash.insert(b);
			}

			
		}
	}
}

void pntr(vector<int> &a){


        vector<vector<int>> result;
        
        if (a.size()==0)
            return ;
        
        
        sort(a.begin(), a.end());
        
        for(int i=0; i<a.size()-1; i++){
		//skip duplicate - we do the same for l and r below 
            if ((i>0)&&(a[i]==a[i-1])) continue;
                
            
            int l=i+1;
            int r=a.size()-1;
            
            while(l<r){
                if(a[i]+a[l]+a[r]==0){
                    result.push_back({a[i],a[l],a[r]}); 
					//skip duplicate 
                    while ((l<r)&&(a[l]==a[l+1]))
                        l++;
                    
					//skip duplicate
                    while((l<r)&&(a[r]==a[r-1]))
                        r--;
                    
                    l+=1;
                    r-=1;
                        
                }
                else if (a[i]+a[l]+a[r]<0){
                    l++;
                }
                else if (a[i]+a[l]+a[r]>0){
                    r--;
                }
            
            }
        }
        
 
        for(int i = 0; i < result.size(); i++){
        	for(int j = 0; j < result[i].size(); j++){
        		cout<<result[i][j]<<" ";
        	}
        }
    
		

}


int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i =0; i < n; i++){
		cin>>a[i];
	}

	//tripletSum(a);
	pntr(a);
}