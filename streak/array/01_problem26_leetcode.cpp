///////////////////// Remove duplicates element from sorted array

#include <bits/stdc++.h>
using namespace std;

///////////////////////////////////////////////////////// brute force approch (Using set)
// int removeDuplicate(vector<int> &arr){
//     set<int> s;
//     int i =0;
//     for(int i=0; i<arr.size(); i++){
//         s.insert(arr[i]);
//     }

//     for(int x : s){
//         arr[i++] = x;
//     }
//     return i;
// }
// int main() {

//     vector<int> arr = {0,0,1,1,1,2,2,3,3,4};
//     cout<<removeDuplicate(arr)<<endl;
//     for(int i: arr){
//         cout<<i<<" ";
//     }
//     return 0;
// }
////////////////////////////////////////////////// it take TC -> O(n) & SC -> O(n)

///////////////////////////////////////////////////// better approach (two pointer approach)
#include <bits/stdc++.h>
using namespace std;

int removeDuplicate(vector<int> &arr){
    int k=1;

    for(int i=1; i<arr.size(); i++){
        if(arr[i] != arr[k-1]){
            arr[k] = arr[i];
            k++;
        }
    }
    return k;
}
////////////////////////////////////// it takes TC -> O(n) & SC -> O(1) 
 
int main() {

    vector<int> arr = {0,0,1,1,1,2,2,3,3,4};
    cout<<removeDuplicate(arr)<<endl;
    for(int i: arr){
        cout<<i<<" ";
    }
    return 0;   
}