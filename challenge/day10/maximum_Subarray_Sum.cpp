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

// Time complexity = O(n) and Space complexity = O(1)

// If I have to return that subarray also then ->

// #include<iostream>
// #include<algorithm>
// #include<climits>
// using namespace std;

//     int maxSubArraySum(int arr[], int n, int &start,int &end){
//         int max = INT_MIN;
//         int sum = 0;
//         int currentStart = 0;
//         for(int i=0; i<n; i++){
//             sum += arr[i];

//             if(sum > max){
//                 max = sum;
//                 start = currentStart;
//                 end = i;
//             }

//             if(sum <  0){
//                 sum = 0;
//                 currentStart = i + 1;
//             }
//         }
//         return max;
//     } 
// int main(){
//     int arr[] = {-2,-3,4,-1,-2,1,5,3};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     int start,end;

//     int maxSum = maxSubArraySum(arr, size, start,end);
//     cout<<"Maximum Sum : "<<maxSum<<endl;
//     cout<<"Maximum Subarray : ";

//     for(int i=start; i<= end; i++){
//         cout<<arr[i]<<" ";
//     }

// return 0;
// }