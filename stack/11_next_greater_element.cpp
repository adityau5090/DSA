            //   Ex -> [6,0,8,1,3]   NGE -> [8,8,-1,3,-1]

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextGreaterElement(vector<int> &arr){
    int size = arr.size();
    vector<int> nge(size);
    stack<int> st;

    for(int i=size-1; i>=0; i--){
        while(!st.empty() && st.top() < arr[i]){
            st.pop();
        }
        if(st.empty()){
            nge[i] = -1;
        }else{
            nge[i] = st.top();
        }
        st.push(arr[i]);
    }
    return nge;
}

int main(){
    vector<int> arr = {6,0,8,1,3};

    vector<int> res = nextGreaterElement(arr);

    for(int i: res){
        cout<<i<<" ";
    }
}

// Time complexity -> O(2n)