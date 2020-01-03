

// Container With Most Water leetcode
// or largest rectangle on haclerrank

#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &heights){

	int n = heights.size();
	int r = n - 1;
	int l = 0;

	int area = min(heights[l],heights[r])* (r-l);

	while(l < r){
		//cout<<"Area "<<area<<endl;
		if(heights[l]<heights[r]){
			l++;
		}
		else{
			r--;
		}

		area = max(area, min(heights[l],heights[r])*(r-l) );
	}

	return area;
}

int main(){
	int n;
	cin>>n;
	vector<int> heights(n);
	for(int i = 0; i < n; i++){
		cin>>heights[i];
	}

	cout<<maxArea(heights)<<endl;
}

