

#include<cstdio>
#include<bits/stdc++.h>
using namespace std;

struct box{	
	int weight;
	int price;
	
};

bool cmp(struct box a, struct box b){
	double r1 = (double)a.price / a.weight;
	double r2 = (double)b.price / b.weight;
	return r1 > r2;
}

double getmaxCost(struct box items[], int n, int capicity){
	sort(items, items + n, cmp);

	double maxCost = 0.0;
	int currWeight = 0;
	for(int i = 0; i < n; i++){
		if(items[i].weight + currWeight <= capicity){
			maxCost += items[i].price*1.0;
			currWeight += items[i].weight;
		}
		else{
			int remain = capicity- currWeight;
			maxCost +=  items[i].price * ((double)remain/items[i].weight);
			break;
		}
	}

	return (maxCost);

}

int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int capicity;
		scanf("%d",&capicity);
		box items[n];
		for(int i = 0; i < n; i++){
			int pr;
			scanf("%d",&pr);
			items[i].price = pr;
			int wt;
			scanf("%d",&wt);
			items[i].weight = wt;
		}
		double ans =  getmaxCost(items, n,capicity);
		printf("%.2lf\n",ans);
	}
}
