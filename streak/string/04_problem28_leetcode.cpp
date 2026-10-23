// Find The Index Of First Occurence In String

#include <bits/stdc++.h>
using namespace std;

int findIndex(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();

    if(m > n) return -1;

    for(int i=0; i<=n-m; i++){
        for(int j=0; j<m; j++){
            if(haystack[i + j] != needle[j]){
                break;
            }
            if(j == m-1) {
                return i;
            }
        }
    }
    return -1;
}
int main() {

    string haystack = "vgsadbutsad";
    string needle = "sad";      

    cout<<"First index : "<<findIndex(haystack, needle);

    return 0;
}

// int n = haystack.size();
//     int m = needle.size();

//     for(int i=0; i<=n-m; i++){
//         if(haystack.substr(i, m) == needle){
//             return i;
//         }
//     }