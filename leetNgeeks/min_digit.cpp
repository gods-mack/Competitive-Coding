

/* Smallest number by rearranging digits of a 
 * given number
 *
 * Find the Smallest number (Not leading Zeros) which 
 * can be obtained by rearranging 
 * the digits of given number. 

 */

# include<bits/stdc++.h>
using namespace std;

int main() {
	
	string num;
	cin>>num;
	sort(num.begin(),num.end());

	if(num[0] == '0') {
		int zero = 0;
		int i = 0;
		while(num[i] == '0'){
			zero++;
			i++;

		}

		string ans = "";
		ans += num[i++];
		while(zero--) {
			ans += '0';
		}
		for(int j = i; j < num.length(); j++) {
			ans += num[j];
		}

		cout<<ans;	

	}
	else{
		cout<<num<<endl;
	}
}


// ANother approach

int smallest(int num ){
	int freq[10] = {0};

	while(num) {
		int d = num%10;
		freq[d]++;
		num = num/10;
	}

	int res = 0;

	// Set the LEFTMOST digit to minimum expect 0 
	for(int i = 1; i < 9; i++) {
		if(freq[i]) {
			res = i;
			freq[i]--;
			break;
		}
	}

	for(int i = 0; i < 9; i++) {

		while(freq[i]--){
			res = res*10 + i;
		}
	}

	return res;
}