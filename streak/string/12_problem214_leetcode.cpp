// Shortest Palindrome

#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(string str){  // Longest prefix table
    int n = str.length();

    vector<int> LPS(n, -1);
    LPS[0] = 0;
    int i=1, j=0;

    while(i < n){
        if(str[j] == str[i]){
            j++;
            LPS[i] = j;
            i++;
        }else{
            if(j != 0){
                j = LPS[j-1];
            }else{
                LPS[i] = 0;
                i++;
            }
        }

    }
    return LPS;
}

string shortestPalindrome(string s){
    if(s.empty()) return s;

    string rev = s;
    reverse(rev.begin(), rev.end());

    string temp = s + "#" + rev;
    int n = temp.length();
    
    vector<int> LPS = buildLPS(temp);

    int longest_palindrome_length = LPS.back();

    return rev.substr(0, s.length() - longest_palindrome_length) + s;
}
int main() {

    string s= "aacecaaa";

    cout<<shortestPalindrome(s);

    return 0;
}