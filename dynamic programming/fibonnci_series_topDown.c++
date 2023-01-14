#include<iostream>
using namespace std;

int series(int n,int dp[]){
	if(n==0||n==1) return n;
	if(dp[n]!=0) return dp[n];
	return dp[n]=series(n-1,dp)+series(n-2,dp);
}

int main(){
	int n=5,m=10;
	int dp[n*m];
	cout<<series(n,dp);
}
