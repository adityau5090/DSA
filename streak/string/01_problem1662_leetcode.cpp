// Check If Two Strings Are Equivalent

#include <bits/stdc++.h>
using namespace std;

bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2){

    string w1 = "",w2 = "";
    for(string w: word1){
        w1 += w;
    }
    for(string w: word2){
        w2 += w;
    }

    return w1 == w2;
}
// TC -> O(n+m)  SC -> O(n+m)

bool arrayStringsAreEqual2(vector<string> &word1, vector<string> &word2){

    int i1=0,i2=0;
    int w1=0, w2=0;

    while(w1 < word1.size() && w2 < word2.size()){
        if(word1[w1][i1] != word2[w2][i2]) return false;
        
        i1++; 
        i2++;

        if(i1 == word1[w1].size()) {
            w1++;
            i1 = 0;
        }

        if(i2 == word2[w2].size()){
            w2++;
            i2=0;
        }
    }

    return w1 == word1.size() && w2 == word2.size();
}
int main() {

    vector<string> word1 = {"abc", "d", "defg"}; 
    vector<string> word2 = {"abcddefg"}; 
    bool res = arrayStringsAreEqual2(word1, word2);
    if(res == 1) cout<<"True, Both are equal";
    else cout<<"False";

    return 0;
}