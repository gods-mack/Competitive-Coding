
// https://www.geeksforgeeks.org/amazon-interview-experience-for-software-development-engineer-ii/

#include<bits/stdc++.h>
using namespace std;


void getNumberOfOptions(vector<int> jeans,vector<int> shoes,vector<int> skirts,vector<int> tops,int dollar) {


	int sum = 0;

	for(auto jns:jeans) {
		sum = 0;
		sum += jns;
		if(sum > dollar) break;

		for(auto shoe:shoes){
			int sum1 = sum;
			sum1 += shoe;
			if(sum1 > dollar) break;
			
			for(auto top:tops){
				int sum2 = sum1;
				sum2 += top;
				if(sum2 > dollar) break;

				for(auto skirt:skirts){
					int sum3 = sum2;
					sum3 += skirt;
					if(sum3 > dollar) break;

					if(sum3 <= dollar) {
						cout<<"#Case "<<sum3<<"\n";
					}
				}
			}
		}
	}
}

int main() {
	vector<int> jeans 	= {2,3};
	vector<int> shoes 	= {4};
	vector<int> skirts 	= {2,3};
	vector<int> tops 	= {1,2};

	int budget; cin>>budget;

	getNumberOfOptions(jeans,shoes,skirts,tops, 10);

}