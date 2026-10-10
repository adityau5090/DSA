///// Container Wtih most Water

#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> & heights){
    int n = heights.size();
    int maxWater = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int height = min(heights[i], heights[j]);
            int width = j-i;
            maxWater = max(maxWater, (height*width));
        }
    }
    return maxWater;
}
////// TC -> O(n^2)   Sc -> O(1)

///////////////////////////////////////   Two pointer approach
int maxArea2(vector<int> & heights){
    int n = heights.size();
    int maxWater = 0;
    int left=0, right=n-1;

    while(left < right){
        int h = min(heights[left], heights[right]);
        int width = right - left;
        int area = h * width;

        maxWater = max(maxWater, area);

        if(heights[left] < heights[right]){
            left++;
        }else{
            right--;
        }
    }
    
    return maxWater;
}
////// TC -> O(n)

int main() {

    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<< "Max area : "<<maxArea2(height);

    return 0;
}