

// Majority Element 
// https://www.geeksforgeeks.org/majority-element/

#include<bits/stdc++.h>
using namespace std;


int find_candidate(vector<int> &a,int n) {

	int maj_ind = 0;
	int count = 1;

	for(int i = 1; i < n; i++) {
		if(a[maj_ind] == a[i]) {
			count++;
		}
		else{
			count--;
		}

		if(count == 0) {
			maj_ind = i;
			count = 1;
		}
	}

	return maj_ind;
}


bool is_majority(vector<int> &a,int x) {

	int count = 0;
	int n  = a.size();

	for(int i = 0; i < n; i++) {
		if(a[x] == a[i]) {
			count++;
		}
	}

	if(count > n/2) {
		return true;
	}
	return false;
}

int majorityElement(vector<int> &a, int size)
{
    
    // your code here
    int ele = find_candidate(a,size);
    if(is_majority(a,ele)) {
        return ele;
    }
    return -1;
    
}

int main() {
	int n; cin>>n;
	vector<int> a(n);
	for(auto &x:a) {
		cin>>x;
	}

	cout<<majorityElement(a,n);


}