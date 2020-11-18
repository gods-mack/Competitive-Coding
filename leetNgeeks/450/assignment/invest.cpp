#include<bits/stdc++.h>
using namespace std;

// Investor class to represent a indivi
class investor {
	string name;      // name of investor
	double net_worth; // net worth of a investor
public:
	// constructor
	
    investor(string name_ , double amount) 
        : name(name_), net_worth(amount) 
    { 
    } 

    // additional comparator operator overl. function 
    // to organize priority queue in Top order
	struct comparator{
	 	bool operator()(investor v1, investor v2) {
			return v1.net_worth < v2.net_worth;
		}
	};


	static void top_k_investors(int k,priority_queue<investor, vector<investor>, investor::comparator> pq) {

		// we are using Priority Queue for
		// finding top K investors
		// it will take O(n * log (k)) time

		cout<<"*** TOP K INVESTORS *** \n";
		while(k-- ) {
			cout<<pq.top().name << " " << pq.top().net_worth<<endl;
			pq.pop();
		}
	}

};

int main() {
	cout<<"Enter number of investors\n";
	int N; cin>>N; // number of investors

	// efficient data structure to find top K investor
	// it will take O ( n * log(K) ) time
	priority_queue<investor, vector<investor>, investor::comparator> pq;

	for( int i = 0; i < N; i++) {
		
		string name; cin>>name;     // input name of investor
		double amount; cin>>amount; // networth of investor
		
		pq.push(investor(name, amount)); // push to heap or queue
		
	}

	cout<<"Enter value of K\n";
	int k; cin>>k;

	// we are using priority queue to find top K investors
	investor::top_k_investors(k, pq);

}