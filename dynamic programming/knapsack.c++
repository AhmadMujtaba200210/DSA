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
