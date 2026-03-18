//  all character hasing (a,b,A,B,#,&,*....) -> 256 characters total

#include<iostream>
using namespace std;

int main(){
    
    string s;
    cout<<"Enter s :"; 
    cin>>s;

    // pre compute
    int hash[256] = {0};
    for(int i=0; i<s.size(); i++){
        hash[s[i]]++;
    }
    

    int q;
    cout<<"Enter  q: ";
    cin>>q;
    while(--q){
        char c;
        cout<<">";
        cin>>c;

        // fetching
        cout<<"No of times present :"<<hash[c] <<endl;
    }

return 0;
}