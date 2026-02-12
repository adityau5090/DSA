                                // minimum in stack
#include<iostream>
#include<stack>
#include<climits>
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

// int main(){
//     Stack s;
//     s.push(3);
//     s.push(7);
//     s.getMin();
//     s.push(4);
//     s.push(9);
//     s.push(2);
//     s.getMin();
//     s.pop();
//     s.getMin();
// }
                                // Time complexity -> O(1)
                                // Space complexity -> O(2*n) because we store pair


class MinStack{
    stack<int> st;
    int min = INT_MAX;

    void push(int val){
        if(st.empty()){
            min = val;
            st.push(val);
        }else{
            if(val > min){
                st.push(val);
            }else{
                st.push(2 * val - min);
                min = val;
            }
        }
    }    

    void pop(){
        if(st.empty()){
            return;
        }

        int x = st.top();
        st.pop();

        if(x < min){
            min = 2 * min - x;
        }
    }

};

int main(){
    cout<<INT_MAX;
}