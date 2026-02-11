#include<iostream>
#include<stack>
using namespace std;

string postfixToInfix(string val){
    int i=0;
    stack<string> st;

    while(i < val.size()){
        if((val[i] >= 'A' && val[i] <= 'Z') || (val[i] >= 'a' && val[i] <= 'z') || (val[i] >= '0' && val[i] <= '9')){
            string op(1, val[i]);
            st.push(op);
        }else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string conv = "(" + t2 + val[i] + t1 + ")";
            st.push(conv);
        }
        i++;
    }

    return st.top();
}

int main(){
    string prefix = "AB+CD-*"
;
    cout << postfixToInfix(prefix);
}