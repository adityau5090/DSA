#include <bits/stdc++.h>
using namespace std;

////////////////////////////////////////////////  Brute force approach
double median(vector<int> &a, vector<int> &b){
    vector<int> arr;
    int n1 = a.size();
    int n2 = b.size();
    int i=0, j=0;

    while(i<n1 && j<n2){
        if(a[i] < b[j]){
            arr.push_back(a[i++]);
        }else{
            arr.push_back(b[j++]);
        }
    }
    while(i<n1){
        arr.push_back(a[i++]);
    }
    while(j<n2){
        arr.push_back(b[j++]);
    }

    int size = arr.size();
    if(size % 2 == 1){
        return arr[size/2];
    }else{
        return (double)((double)arr[size/2] + (double)arr[size/2-1])/2.0;
    }   
}
/////// TC -> O(n1+n2)  SC -> O(n1+n2)

/////////////////////////////////////////////////  Better approach
double median2(vector<int> a, vector<int> b){
    int n1 = a.size();
    int n2 = b.size();

    int i=0, j=0;

    int n = (n1+n2);
    int ind1 = n/2, ind2 = ind1 -1;
    int count = 0;
    int ind1el = -1, ind2el = -1;

    while(i<n1 && j<n2){
        if(a[i] < b[j]){
            if(count == ind1) ind1el = a[i];
            if(count == ind2) ind2el = a[i];
            count++;
            i++;
        }else{
            if(count == ind1) ind1el = b[j];
            if(count == ind2) ind2el = b[j];
            count++;
            j++;
        }
    }
    while(i<n1){
        if(count == ind1) ind1el = a[i];
        if(count == ind2) ind2el = a[i];
        count++;
        i++;
    }
    while(j<n2){
        if(count == ind1) ind1el = b[j];
        if(count == ind2) ind2el = b[j];
        count++;
        j++;
    }
    if(n%2==1) return ind1el;
    return (double)((double)(ind1el + ind2el)/2.0);
}
//////// TC -> O(n1+n2)    SC -> O(1)


///////////////////////////////////////// Best approach (using Binary Search)
double median3(vector<int> a, vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    if(n1 > n2) return median3(b,a);// apply binary search on smallest array

    int low =0, high = n1;
    int left = (n1+n2+1)/2; // required element in left symmetry
    int n = n1+n2;
    while(low<=high){
        int mid1 = (low+high)/2;
        int mid2 = left - mid1;
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if(mid1 < n1 ) r1 = a[mid1];
        if(mid2 < n2 ) r2 = b[mid2];
        if(mid1-1 >= 0) l1 = a[mid1-1];
        if(mid2-1 >= 0) l2 = b[mid2-1];

        if(l1 <= r2 && l2 <= r1){
            if(n%2==1) return max(l1,l2);
            return ((double)(max(l1,l2)+min(r1,r2))/2.0);
        }else if(l1 > r2){
            high = mid1 -1;
        }else{
            low = mid1 + 1;
        }
    }
    return 0;
}
////// TC -> O(min(logn, logm))
int main() {

    vector<int> a = {1, 3, 4,7,10,12};
    vector<int> b = {2,3,6,15};

    cout<<"Median : "<<median3(a,b);

    return 0;
}