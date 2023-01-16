#include<iostream>
using namespace std;

int knapsack(int weight[],int prices[],int total_items,int total_weight){
	// base case
	if(total_items==0||total_weight==0) return 0;

	// recursive case
	int inc=0,exc=0;
	if(weight[total_items-1]<=total_weight){
		inc=prices[total_items-1]+knapsack(weight,prices,total_items-1,total_weight-weight[total_items-1]);
	}
	exc=0+knapsack(weight,prices,total_items-1,total_weight);
	return max(inc,exc);
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