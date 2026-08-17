// Kadane's Algorithm

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

    int maxSubArraySum(int arr[], int n){
        int max = INT_MIN;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];

            if(sum > max){
                max = sum;
            }

            if(sum <  0){
                sum = 0;
            }
        }
        return max;
    } 
int main(){
    int arr[] = {-2,-3,4,-1,-2,1,5,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<maxSubArraySum(arr, size);

return 0;
}