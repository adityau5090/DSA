#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int> &stalls, int cows, int distance){
    int count = 1;
    int lastPosition = stalls[0];

    for(int i=1; i<stalls.size(); i++){

        // if distance is far enough
        if((stalls[i] - lastPosition) >= distance){
            //place a cow here
            count++;
            lastPosition = stalls[i];
        }

        // if we have placed all cows
        if(count >= cows){
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int cows){
    sort(stalls.begin(), stalls.end());
    // lets define our search space 
    // minimum distance should be 1 because we can't place two cows at same stall
    int low = 1;
    // maximum distance - imagine we hav only 2 cows so where we put to get the largest possible distance ? -
    // obviously at smallest stall and largest stall 
    int high = stalls.back() - stalls.front();
    int answer = 0;

    while(low<=high){
        int mid = (low+high)/2;

        if(canPlace(stalls, cows, mid)){
            //mid is possible
            // try for even larger distance
            answer = mid;
            low = mid + 1;
        }else{
            // mid is not possible
            high = mid - 1;
        }

    }
    return answer;
}
int main() {

    vector<int> stalls = {1, 2, 4, 8, 9};

    int cows = 3;

    cout << "Maximum minimum distance: "<< aggressiveCows(stalls, cows);


    return 0;
}
