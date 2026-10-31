// Knuth-Morris-Pratt Algorithm

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

int KMP(string text, string pattern){
    int n= text.length();
    int m= pattern.length();
    vector<int> LPS = buildLPS(pattern);

    int i=0, j=0;

    while(i < n){
        if(text[i] == pattern[j]){
            i++; j++;

            if(j==m){
                return i-j;
            }

        }else if(i<n && text[i] != pattern[i]){
            if(j != 0){
                j = LPS[j-1];
            }else{
                i++;
            }
        }
    }
    return -1;
}
int main() {

    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    cout<<"Substr at index : "<<KMP(text, pattern);

    return 0;
}