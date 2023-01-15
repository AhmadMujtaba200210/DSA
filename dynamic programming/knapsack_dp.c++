#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
  
int knapsack(int wt[],int price[],int N,int W){
	vector<vector<int> > dp(N+1,vector<int>(W+1,0));

	for(int n=1;n<=N;n++){
	  for(int w=1;w<=W;w++){
	   int inc=0,exc=0;
	   if(wt[n-1]<=w){
		inc=price[n-1]+dp[n-1][w-wt[n-1]];
	    } 
		exc=dp[n-1][w];
		dp[n][w]=max(inc,exc);
	  }
	}

	return dp[N][W];
}

int main(){
	int weight[4]={2,7,3,4};
	int prices[4]={5,20,20,10};
	int N=4,W=11;
	time_t start, end;

	time(&start);
	cout<<knapsack(weight,prices,N,W);
	time(&end);

	double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
         << time_taken ;
    cout << " sec " << endl;
}
