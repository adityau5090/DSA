// Knuth-Morris-Pratt Algorithm

#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(string str){
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
int main() {

    string s = "ABACABAB";
    vector<int> res = buildLPS(s);
    for(int i: res){
        cout<<i<<" ";
    }

    return 0;
}