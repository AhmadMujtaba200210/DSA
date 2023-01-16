#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
    for (int i = 1; i <= n-1; i++)
    {
        int current=arr[i];
        int prev=i-1;

        while (prev>=0 and arr[prev]>current)
        {
            arr[prev+1]=arr[prev];
            prev--;
        }
        
        arr[prev+1]=current;
    }
    
}

int main(){
    int arr[]={5,4,1,2,3};
    insertionSort(&arr[0],5);
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<", ";
    }
    
}