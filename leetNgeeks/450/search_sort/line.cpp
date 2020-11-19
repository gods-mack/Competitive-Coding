

#include<bits/stdc++.h>
using namespace std;


class line {
public:
	int a,b,c;
	line() {}
	line(int a_, int b_, int c_) {
		a = a_;
		b = b_;
		c = c_;
	}
};

class point {
public:
	int a,b;
	point() {}
	point(int a_, int b_) {
		a = a_;
		b = b_;
	}
};




int main() {    
 
	int n; cin>>n;
	point *point_array  = new point[n];

	int x_max = 	 
	int x_min = 
	int y_max = 
	int y_min = 
	for(int i = 0; i < n; i++) {
		int x,y; cin>>x>>y;
		point_array[i] = point(x,y);
	}

	line l(1,2,4);

}