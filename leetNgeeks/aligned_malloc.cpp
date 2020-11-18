

#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;


int main() {

	cout<<sizeof(size_t)<<endl;
	int mem; cin>>mem;
	int align ; cin>>align;

	void *p1 = (void*)malloc(mem+align+sizeof(size_t));

	size_t addr = (size_t)p1+align+sizeof(size_t);
	cout<<(size_t)p1<<endl;
	cout<<addr<<endl;
	
		void *p2=(void *)(addr - (addr%align));
		*((size_t *)p2-1)=(size_t)p1;
		cout<<(size_t)p2;
	free(p1);
}