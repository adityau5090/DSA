                                // minimum in stack
#include<iostream>
#include<stack>
using namespace std;

class Stack{

    stack<pair<int,int>> st;

    public:
    
    void push(int val){
        if(st.empty()){
            st.push({val,val});
        }else{
            st.push({val,min(val,st.top().second)});
        }
    }

    void pop(){
        st.pop();
    }

    void getMin(){
        cout<<"Min : "<<st.top().second<<"\n";
    }
};

int main(){
    Stack s;
    s.push(3);
    s.push(7);
    s.getMin();
    s.push(4);
    s.push(9);
    s.push(2);
    s.getMin();
    s.pop();
    s.getMin();
}
                                // Time complexity -> O(1)
                                // Space complexity -> O(2*n)