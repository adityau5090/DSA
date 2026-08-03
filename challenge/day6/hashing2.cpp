// now let's hash characters

// #include<iostream>
// #include<vector>
// using namespace std;
//     int hashAndSearcrh(vector<char> arr, char target){
//         vector<int> hashArray(256,0);
//         for(int i=0; i<arr.size(); i++){
//             hashArray[arr[i]] += 1;   
//         }

//         return hashArray[target];
//     }
// int main(){
//     vector<char> arr = {'a','b','c','d','a','b','e','h','f'};
//     cout<<hashAndSearcrh(arr, 'y');
// return 0;
// }


// hash only small alphabet

#include<iostream>
#include<vector>
using namespace std;
    int hashAndSearcrh(vector<char> arr, char target){
        vector<int> hashArray(26,0);
        for(int i=0; i<arr.size(); i++){
            hashArray[arr[i] - 'a'] += 1;   
        }

        return hashArray[target - 'a'];
    }
int main(){
    vector<char> arr = {'a','b','c','d','a','b','e','h','f'};
    cout<<hashAndSearcrh(arr, 'b');
return 0;
}
