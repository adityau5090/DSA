                        // Striver's Greedy algorithm Playlist
/* We have to satisfy the greed by assgin cookies to them. Remember the cookies must have grater than or equal to greed which it have to be assign. We can not reuse cookies once it assigned */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int max_greed_Assigned(vector<int> greed, vector<int> cookies){
    int n = greed.size(); 
    int m = cookies.size();
    int i=0,j=0;

    sort(greed.begin(), greed.end());
    sort(cookies.begin(), cookies.end());

    while(j < m){
        if(greed[i] <= cookies[j]){
            i += 1;
        }
        j += 1;
    }
    
    return i;
}

int main(){
    vector<int> greedy = {1,5,3,3,4};
    vector<int> cookies = {4,2,1,2,1,3};

    int result = max_greed_Assigned(greedy,cookies);
    cout<<"Max greed assigned : "<<result;
}