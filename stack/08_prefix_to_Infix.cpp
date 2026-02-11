#include<iostream>
#include<stack>
using namespace std;

string prefixToInfix(string val){
    int i=val.size()-1;
    stack<string> st;

    while(i >= 0){
        if((val[i] >= 'A' && val[i] <= 'Z') || (val[i] >= 'a' && val[i] <= 'z') || (val[i] >= '0' && val[i] <= '9')){
            string op(1, val[i]);
            st.push(op);
        }else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string conv = "(" + t1 + val[i] + t2 + ")";
            st.push(conv);
        }
        i--;
    }

    return st.top();
}

int main(){
    string prefix = "*+AB-CD";
    cout << prefixToInfix(prefix);
}