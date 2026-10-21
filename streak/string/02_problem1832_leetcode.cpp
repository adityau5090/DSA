// Check if sentence Is Pangram (A pangram is a sentence where every letter of the English alphabet appears at least once)

#include <bits/stdc++.h>
using namespace std;

bool checkIfPangram(string sentence){
    if(sentence.length() < 26) return false;

    for(char i='a'; i <= 'z'; i++){
        int count=0;
        for(int j=0; j<sentence.length(); j++){
            if(i == sentence[j]) count ++;
        }
        if (count == 0) return false;
    }
    return true;

}
// TC -> O(n * 26) or in some case O(n^2) or O(n)                  SC -> O(1)

bool checkIfPangram2(string sentence){
    if(sentence.length() < 26) return false;

    vector<bool> arr(26, false);
    int count = 0;
    for(char c: sentence){
        int index = c - 'a';
        if(arr[index] == false){
            count++;
            arr[index] = true;
            if(count == 26) return true;
        }
        
    }
    return count == 26;
}


int main() {

    string sentence = "thequickbrownfoxjumpsoverthelazydog";
    bool res = checkIfPangram2(sentence);
    if(res == 1) cout<<"True";
    else cout<<"False";
    return 0;
}