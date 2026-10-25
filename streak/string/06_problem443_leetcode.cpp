// String Compression

#include <bits/stdc++.h>
using namespace std;

int compress(vector<char> &chars){
    int j=0, count=1;

    for(int i=0; i<chars.size(); i++){
        
        if(i == chars.size() - 1 || chars[i] != chars[i+1]) {
            chars[j++] = chars[i];

            if(count > 1){
                for(char c : std::to_string(count)){
                    chars[j++] = c;
                }
            }
            count = 1;
        }else{
            count++;
        }
    }
    return j;
}
int main() {

    vector<char> str = {'a','a','b','b','c','c','c'};
    cout<<"Compressed Array size : "<<compress(str);

    return 0;
}