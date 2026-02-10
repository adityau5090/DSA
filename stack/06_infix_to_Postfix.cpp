#include <iostream>
#include <stack>
using namespace std;

int priority(char ch){
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '^') return 3;
    return -1;
}

string infixToPostfix(string val){
    int i = 0;
    stack<char> st;
    string ans = "";

    while(i < val.size()){

        // Operand
        if((val[i] >= 'A' && val[i] <= 'Z') ||
           (val[i] >= 'a' && val[i] <= 'z') ||
           (val[i] >= '0' && val[i] <= '9')){
            ans += val[i];
        }

        // Opening bracket
        else if(val[i] == '('){
            st.push(val[i]);
        }

        // Closing bracket
        else if(val[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }

        // Operator
        else{
            while(!st.empty() && priority(val[i]) <= priority(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(val[i]);
        }

        i++;
    }

    // Pop remaining operators
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    return ans;
}


 
int main(){
    cout << infixToPostfix("a+b*(c^d-e)^(f+g*h)-i");
}
