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
            if(count == ind2) ind2el = a[j];
            count++;
            i++;
        }else{
            if(count == ind1) ind1el = b[i];
            if(count == ind2) ind2el = b[j];
            count++;
            j++;
        }
    }
    while(i<n1){
        if(count == ind1) ind1el = a[i];
        if(count == ind2) ind2el = a[j];
        count++;
        i++;
    }
    while(j<n2){
        if(count == ind1) ind1el = b[i];
        if(count == ind2) ind2el = b[j];
        count++;
        j++;
    }
    if(n%2==1) return ind1el;
    return (double)((double)(ind1el + ind2el)/2.0);
}

int main() {

    vector<int> a = {1, 3};
    vector<int> b = {2, 4,5};

    cout<<"Median : "<<median2(a,b);

    return 0;
}