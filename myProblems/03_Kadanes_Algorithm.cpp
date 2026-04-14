//   Find the maximum sub array sum 

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

// int maxSubArraySum(vector<int> vec){
//     int maxSum = INT_MIN;
//     for(int i=0; i<vec.size(); i++){
//         int sum = 0;
//         for(int j=i; j<vec.size(); j++){
//             sum += vec[j];
//             maxSum = max(maxSum, sum);
//         }
//     }
//     return maxSum;

//     // Time complexity = O(n^2)
// }


// Kadane's Algorithm
int maxSubArraySum(vector<int> vec){
    vector<int> arr;
    int sum=0;
    int maxSum = INT_MIN;
    for(int i=0; i<vec.size(); i++){
        sum += vec[i];

        if(sum < 0){
            sum = 0;
        }
        maxSum = max(maxSum, sum);
    }
    for(int i: arr){
        cout<<i<<",";
    }
    cout<<"\n";
    return maxSum;

    // Time complexity = O(n)  Space complexity = O(1)
}

int main(){
    vector<int> vec = {-2,-3,4,-1,-2,1,5,-3};
    int ans = maxSubArraySum(vec);
    cout<<"Max subArray sum : "<<ans<<"\n";

return 0;
}