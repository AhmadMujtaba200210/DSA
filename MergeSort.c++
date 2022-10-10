#include<bits/stdc++.h>
using namespace std;
void mergeSort(vector<int> &arr,int s,int e){
	if(s>=e){
		return;
	}
	
	int mid=(s+e)/2;
	mergeSort(arr,s,mid);
	mergeSort(arr,mid+1,e);
	return merge(arr,s,e);
}

int main(){
	vector<int> arr;
	arr.push(10);
	arr.push(7);
	arr.push(11);
	arr.push(5);
	arr.push(3);
	arr.push(9);
	
	for(int x : arr){
		cout<<x<<" ";
	}
	cout<<endl;
	mergeSort(arr,arr.begin(),arr.end());
	
	for(int x : arr){
		cout<<x<<" ";
	}

	cout<<endl;
	return 0;
}
