//   small character hasing (a,b,c,d,....) -> 26 alphabets

#include<iostream>
using namespace std;

int main(){
    
    string s;
    cout<<"Enter s :"; 
    cin>>s;

    // pre compute
    int hash[26] = {0};
    for(int i=0; i<s.size(); i++){
        hash[s[i] - 'a']++;
    }
    

    int q;
    cout<<"Enter  q: ";
    cin>>q;
    while(--q){
        char c;
        cout<<">";
        cin>>c;

        // fetching
        cout<<"No of times present :"<<hash[c-'a'] <<endl;
    }

return 0;
}