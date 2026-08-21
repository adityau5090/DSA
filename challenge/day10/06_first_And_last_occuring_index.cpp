// first and last occuring index of x

// logic is for first find lower bound and for last find uppe bound -1

// #include<iostream>
// #include<vector>
// using namespace std;
//     int lowerBound(vector<int> vec, int target)
// {
//     int low = 0, high = vec.size() - 1;
//     int ans = vec.size(); // hypothetical index
//     while (low <= high)
//     {
//         int mid = low + (high - low) / 2;

//         if (vec[mid] >= target){
//             ans = mid;
//             high = mid - 1;
//         }
//         else{
//             low = mid + 1;
//         }
//     }
//     return ans;
// }

//     int upperBound(vector<int> vec, int target)
// {
//     int low = 0, high = vec.size() - 1;
//     int ans = vec.size(); // hypothetical index
//     while (low <= high)
//     {
//         int mid = low + (high - low) / 2;

//         if (vec[mid] > target){
//             ans = mid;
//             high = mid - 1;
//         }
//         else{
//             low = mid + 1;
//         }
//     }
//     return ans;
// }
    

// pair<int,int> firsrAndLastOccurence(vector<int> vec, int target){
//     int lb = lowerBound(vec,target);
//     if(lb == vec.size()-1 || vec[lb] != target){
//         return {-1, -1};
//     }
//     return {lb, upperBound(vec, target)-1};
// }
// int main(){
//     vector<int> vec = {2,4,6,8,8,8,11,13};
//     pair<int,int> res = firsrAndLastOccurence(vec,8);
//     cout<<res.first<<","<<res.second;
// return 0;
// }

// // Time complexity = 2 * O(logn)

// Now let's do this without using lower and upper bound

#include<iostream>
#include<vector>
using namespace std;
    int firstOccurence(vector<int> vec, int target){
        int low = 0;
        int high = vec.size()-1;
        int ans = -1;

        // for first occurence
        while(low<=high){
            int mid = low + (high-low)/2;

            if(vec[mid] == target){
                ans = mid;
                high = mid-1;
            }else if(vec[mid] < target){
                low = mid+1;
            }else{
                high = mid -1;
            }
        }
        return ans;
    }
    int lastOccurence(vector<int> vec, int target){
        int low = 0;
        int high = vec.size()-1;
        int ans = -1;

        // for last occurence
       while(low<=high){
            int mid = low + (high-low)/2;

            if(vec[mid] == target){
                ans = mid;
                low = mid +1;
            }else if(vec[mid] < target){
                low = mid + 1;
            }else{
                high = mid -1;
            }
        }
        return ans;
    }
    pair<int,int> fistAndLastPosition(vector<int> vec, int target){
        int  first = firstOccurence(vec,target);
        if(first == -1) return {-1,-1};
        return {first, lastOccurence(vec,target)};
    }
int main(){
    vector<int> vec = {2,4,6,8,8,8,11,13};
    pair<int,int> res = fistAndLastPosition(vec,8);
    cout<<res.first<<","<<res.second; 
return 0;
}