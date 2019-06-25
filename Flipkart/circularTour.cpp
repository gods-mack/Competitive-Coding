/*

prob. URL : https://practice.geeksforgeeks.org/problems/circular-tour/1

Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.

Your task is to complete the function tour() which returns an integer denoting the first point from where a truck will be
 able to complete the circle (The truck will stop at each petrol pump and it has infinite capacity).

Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.

Input:
1    //(testcase)
4    // no. of petrolpump
4 6 6 5 7 3 4 5

Output:
1

*/



#include<iostream>
using namespace std;

struct petrol_pump{
    int petrol;
    int dis;
};


int tour(petrol_pump pp[],int n){

    int res;
    int ret;
    for(int i=0;i<n;i++){

        res = 0;
        for(int j=i;j<i+n;j++){
            if(res+pp[j%n].petrol >= pp[j%n].dis){
                res = res + (pp[j%n].petrol - pp[j%n].dis);
            }
            else{
                res = -1;
                ret  = -1;
                break;
            }
        }
        if(res >= 0){
           // cout<<" index "<<i<<" patrol "<<pp[i].petrol<<endl;
            ret  = i;
            break;
        }
    }

    if(ret == -1){
        return -1;
    }
    else{
        return ret;
    }
   
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrol_pump pp[n];
        for(int i=0;i<n;i++)
            cin>>pp[i].petrol>>pp[i].dis;
            cout<<tour(pp,n);
    }
}

