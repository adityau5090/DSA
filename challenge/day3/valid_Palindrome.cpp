// palindrome
// -> (i, n-i-1) are opposite of one-another in array

#include<iostream>
using namespace std;
    bool isPalindrome(string s, int i, int n){
        if(i>= n/2) return true;

        if(s[i] != s[n-i-1]) return false;
        return isPalindrome(s, i+1, n);
    }
int main(){
    string str = "madam";
    cout<<isPalindrome(str, 0, str.length());
return 0;
}

// Time complexity and space complexity will be n/2 because it goes only half of array and so only half of array waited in stack