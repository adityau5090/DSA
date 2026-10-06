/* arr = [1,7] k=2 so here k is no. of new gas stations, & we have to place these new gas station in such a way so that the maximum distance between two gas stations should be minimum

Ex - > [1,7]  max distance between two gas station is 6
so if we put these 4 stations before 1 or after 7 so it does not minimize maximum distance so we need put them in between

*/

#include <bits/stdc++.h>
using namespace std;

////////////////////////////////////////////////////////////// brute force approach
long double minimizeMaxDistance(vector<int> &arr, int k){
    int n = arr.size(); 
    vector<int> howMany(n-1, 0);
    for(int gasStations=1; gasStations <= k; gasStations++){
        int maxIndex = -1;
        long  double maxValue = -1;
        for(int i=0; i<n-1; i++){
            long double diff = arr[i+1] - arr[i];
            long double sectionLength = diff/(double)(howMany[i]+1); 
            if(maxValue < sectionLength){
                maxValue = sectionLength;
                maxIndex = i;
            }
        }
        howMany[maxIndex]++;
    }

    long double maxAns = -1;
    for(int i=0; i<n-1; i++){
        long double diff = arr[i+1]-arr[i];
        long double sectionLength = diff/(double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns;
}
// TC -> O(k*n) SC => O(n-1)


////////////////////////////////////////////////////// Better Approach (using priority queue)

long double minimizeMaxDistance(vector<int> &arr, int k){
    int n = arr.size(); 
    vector<int> howMany(n-1, 0);
    priority_queue<pair<long double, int>> pq;

    for(int i=0; i<n-1; i++){
        pq.push({arr[i+1]-arr[i], i});
    }

    for(int gasStations=1; gasStations <= k; gasStations++){
        auto top = pq.top(); 
        pq.pop();

        int sectionInd = top.second;
        howMany[sectionInd]++;
        long double initialDiff = arr[sectionInd + 1] - arr[sectionInd];
        long double newSectionLength = initialDiff/(long double)(howMany[sectionInd] + 1);
        pq.push({newSectionLength, sectionInd});
    }
    return pq.top().first;
}
// TC -> O(nlogn + klogn)    SC -> O(n-1)

int main() {

    vector<int> arr = {1,13,17,23};
    cout<<minimizeMaxDistance(arr, 5);

    return 0;
}