// Reverse word in string

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string str){

    reverse(str.begin(), str.end());

    int n=str.length();
    int end=0;

    for(int i=0; i<n; i++){
        if(str[i] != ' '){
            
            if(end != 0){
                str[end++] = ' ';
            }

            int start = end;
            while(i < n && str[i] != ' '){
                str[end++] = str[i++];
            }
            reverse(str.begin() + start, str.begin() + end);

        } 
    }

    str.erase(str.begin() + end, str.end());
    return str;
}


int main() {

    string s = "  chai  code  ";
    string res = reverseWords(s);

    cout<<"Reversed : "<<res<<endl;
    cout<<"Length : "<<res.length();

    return 0;
}