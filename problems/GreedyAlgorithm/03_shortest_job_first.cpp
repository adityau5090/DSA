#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int sjf(vector<int> vec){
    sort(vec.begin(), vec.end());
    int time = 0;   
    int waitingTime = 0;

    for(int i: vec){
        waitingTime += time;
        time += i;
        cout<<"Process : "<<i<<"  |  ";        
        cout<<"wt :"<<waitingTime<<"\n";
        
    }

    return waitingTime/vec.size();
}

int main(){
    vector<int> processes = {4,3,7,1,2};
    cout<<"Avg waiting time : "<<sjf(processes);
}