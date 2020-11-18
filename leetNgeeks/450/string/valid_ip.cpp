

// check valid IP address

#include<bits/stdc++.h>
using namespace std;



bool isValid(string ip) {

	vector<string> sectors;

	// split by '.'

	int n = ip.length();

	string tmp = "";
	for(int i = 0; i < n; i++) {
		if(ip[i] != '.') {
			tmp += ip[i];
		}
		else{
			sectors.push_back(tmp);
			tmp  = "";
		}
	}
	sectors.push_back(tmp);

	for(auto x:sectors) {
	//	cout<<x<<endl;
	}


	// check valid or not each sector of IP

	for(auto s:sectors) {

		if(s[0] == '0' or s.length() > 3	) {
			return false;
		}
		int num = stoi(s);
		if(num < 0 or num>255) {
			return false;
		}
	} 

	return true;
}



void convert_IP(string ip) {

	vector<string> ans_ips;


	int l = ip.length();
	if(l > 12 or l < 4) {
		cout<<"not a valid IP format\n";
		return;
	}

	string check = ip;
    for (int i = 1; i < l - 2; i++) { 
        for (int j = i + 1; j < l - 1; j++) { 
            for (int k = j + 1; k < l; k++) { 
                check = check.substr(0, k) + "."
                        + check.substr(k, l - k + 2); 
                cout<<"1st "<<check<<endl;        
                check 
                    = check.substr(0, j) + "."
                      + check.substr(j, l - j + 3); 
                      cout<<"2nd "<<check<<endl;
                check 
                    = check.substr(0, i) + "."
                      + check.substr(i, l - i + 4); 
  
                // cout<< check <<endl; 
                // Check for the validity of combination 
                std::cout << check << '\n';
                if (isValid(check)) { 
                    ans_ips.push_back(check); 
                    
                } 
                check = ip; 
            } 
        } 
    } 

	cout<<"valid IP\n";
	for(auto x:ans_ips) {
		cout<<x<<endl;
	}
}

int main() {

	string ip;
	cin>>ip;

	//cout<<isValid(ip);
	string tmp = "manish";
	//cout<<tmp.substr(0,1);
	convert_IP(ip);


}