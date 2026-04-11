// Find longest subarray with sum K  [Subarray -> contiguous part of array]

#include<iostream>
#include<climits>

using namespace std;

// print all the subarray of an array
void printAllSubarray(int arr[],int size){
    int count=0;
    int largestSubarraySum = INT_MIN;
    for(int i=0; i<size; i++){
        for(int j=i; j<size; j++){
            int sum = 0;
            cout<<"[ ";
            for(int k=i; k<=j; k++){
                sum += arr[k];
                cout<<arr[k]<<" ";
            }
            if(sum > largestSubarraySum) largestSubarraySum = sum; 
            cout<<"] "<<"Sum : "<<sum;
            count++;
            cout<<"\n";
        }
    }
    cout<<"Total Subarray : "<<count<<"\n";
    cout<<"Largest subarray : "<<largestSubarraySum;
}


int main(){
    int arr[] = {1,2,3,2,1,1,4,2,3};
    int size = sizeof(arr)/sizeof(int);
    printAllSubarray(arr,size);
return 0;
}