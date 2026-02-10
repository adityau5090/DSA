#include<iostream>
#include<stack>
using namespace std;

int priority(char c){
    if(c == '+' || c == '-') return 1;
    else if(c == '*' || c == '/') return 2;
    else if(c == '^') return 3;
    else return -1; 
}

string reverse(string val){
    string s = "";
    for(int i=val.size()-1; i>=0; i--){
        if(val[i] == '('){
            s +=')'; 
        }else if(val[i] == ')'){
            s += '(';
        }else{
            s += val[i];
        }
    }
    return s;
}

string infixToPrefix(string val){

    // reverse the string 
    string s = reverse(val);

    int i=0;
    stack<char> st;    
    string ans;

    while(i<s.size()){

        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            ans += s[i];
        }

        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            
                while(!st.empty() && priority(s[i]) <= priority(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
            }
        
        i++;
    }

    while(!st.empty()){
        ans += st.top();

        st.pop();
    }


    return reverse(ans);
}

int main(){
    cout<< infixToPrefix("c+d-e*(f+g)");
}