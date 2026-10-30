// Number Of Laser Beams In Bank

#include <bits/stdc++.h>
using namespace std;

int numberOfBeams(vector<string>& bank){
    int n = bank.size();
    int res = 0;
    int prev=0, next=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<bank[i].size(); j++){
            if(bank[i][j] == '1'){
                next++;
            }
        }
        if(prev != 0 && next != 0){
            res += prev * next;
        }
        if(next != 0){
            prev = next;
            next = 0;
        }
    }
    return res;
}

int main(){
    vector<string> bank = {"011001","000000","010100","001000"};

    cout<<"No of laser beams : "<<numberOfBeams(bank);
}