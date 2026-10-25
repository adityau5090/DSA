// Repeated Substring Pattern

#include <bits/stdc++.h>
using namespace std;

bool repeatedSubstring(string s){
    int n = s.length();
    string subs;

    for(int i=n/2; i>=1; i--){
        if(n % i == 0){

            string sub = s.substr(0,i);
            string constructed = "";

            for(int i=0; i<n/i; i++){
                constructed += sub;
            }

            if(constructed == s) return true;
        }

    }
    return false;
}

int main() {

    string s = "abab";

    bool res = repeatedSubstring(s);
    cout<<"Res : "<<res;

    return 0;
}