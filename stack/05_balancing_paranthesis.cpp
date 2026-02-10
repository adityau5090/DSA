// there are paranthesis given and we have to ckeck that evey paranthesis has its opening and closing in right order

#include<iostream>
#include<stack>
using namespace std;

bool checkParanthesis(string p){
    stack<char> s;

    for(int i=0; i<p.size(); i++){
        if(p[i] == '[' || p[i] == '{' || p[i] == '(' ){
            s.push(p[i]);
        }else{
             if(s.empty()){
                return false;
             }
             char ch = s.top();
             s.pop();

             if((p[i] == ']' && ch != '[') ||
               (p[i] == '}' && ch != '{') ||
               (p[i] == ')' && ch != '(')){
                return false;
            }

        }
    }
    return  s.empty();
}

int main(){
    cout << checkParanthesis("{[()]}") << endl;  // (true)
    cout << checkParanthesis("{[(])}") << endl;  // (false)
}