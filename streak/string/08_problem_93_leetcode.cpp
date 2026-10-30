// Restore IP Address

#include <bits/stdc++.h>
using namespace std;

void backtrack(string &s, int start, vector<string>& IpParts, vector<string>& result){
    if(IpParts.size() == 4){
        if(start == s.length()){
            result.push_back(IpParts[0] + "." + IpParts[1] + "." + IpParts[2] + '.' + IpParts[3]);
        }
        return;
    }

    for(int len=1; len<4 && start + len <= s.length(); len++){
        string segments = s.substr(start, len);

        if(len > 1 && segments[0] == '0') break;

        if(stoi(segments) <= 255){
            IpParts.push_back(segments);
            backtrack(s, start+len, IpParts, result);
            IpParts.pop_back();
        }
    }
}

vector<string> restoreIpAddress(string s){
    vector<string> result;
    if(s.length() < 4 || s.length() > 12) return result;

    vector<string> IpParts;
    backtrack(s, 0, IpParts, result);
    return result;
}
// TC -> O(1)  SC-> O(1)


int main(){
    string s = "25525511135";

    vector<string> res = restoreIpAddress(s);

    for(string s: res){
        cout<<s<<", ";
    }
    return 0;
}