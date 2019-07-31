// find inversion in array in O(nlogn)


	#include<bits/stdc++.h>
	using namespace std;



	//int count_Inv = 0;
	long merge(int *a, int left,int mid, int right){

		long  count_Inv = 0;
		int L[(mid- left + 1) ];
		int R[(right - mid)] ;
		
		
		int left_size = mid - left + 1;
		int right_size = right - mid;
		
		for(int i = 0 ;i< left_size; i++){
			L[i] = (a[ left+i ]);
		}
		for(int j = 0 ; j < right_size; j++){
			R[j] = (a[ mid + j + 1]);
		}
		
		int i = 0 , j = 0, k = left ;
		

		while(i < left_size and j < right_size ){

			if(L[i] <= R[j]){
				a[k] = L[i];
				i++;
			}
			else{
			//	cout<<"inversion "<<L[i]<<" "<<R[j]<<endl;
			    int lsize = sizeof(L)/sizeof(L[0]);
				count_Inv  = count_Inv + (lsize - i);
				a[k] = R[j];
				j++;
			}
			k++;
				

		}

		while ( i < left_size){
			
			a[k++] = L[i++];
		}
		while( j < right_size){
			 
			a[k++] = R[j++];
		}
			
		
		
		return count_Inv;
			
				
		
	}  // end of merge

	long merge_sort(int *a, int l,int r){
		
		long count_Inv = 0;
		int mid ;
		if(l < r){
			mid = (l+r) / 2;
			
			count_Inv = merge_sort(a,l,mid);
			count_Inv += merge_sort(a,mid+1,r );	
			count_Inv += merge(a,l,mid,r);
		}
		return count_Inv;
		
	}

	int main(){
	    int T; cin>>T;
	    while(T--){
	    
		int n; cin>>n;
		//int counter = 0;
		int a[(n)];
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		
		long res = merge_sort(a,0,n-1);
		
		cout<<res<<endl;
		 //cout<<"count inversion "<<count_Inv<<endl;
	    }
	}

