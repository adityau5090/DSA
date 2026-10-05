#include <bits/stdc++.h>
using namespace std;

int noOfStudents(vector<int> &books, int pages){
    int stuCount = 1, pageCount = 0;
    for(int i=0; i<books.size(); i++){
        if(pageCount + books[i] > pages){
            stuCount++;
            pageCount = books[i];
        }else{
            pageCount += books[i];
        }
    }
    return stuCount;
}

/////////////////////////// brute force approach 
int bookAllocate(vector<int> &books, int stu){
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);

    for(int i=low; i<= high; i++){
        if(noOfStudents(books, i) <= stu){
            return i;
        }
    }
    return -1;
}

int bookAllocation(vector<int> &books, int stu){
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);

    while(low<=high){
        int mid = (low+high)/2;

        if(noOfStudents(books, mid) > stu){
            low = mid + 1;
        }else{
            high = mid -1;
        }
    }
    return low;
}

int main() {

    vector<int> books = {25,46,28,49,24};
    cout<<bookAllocation(books, 4);

    return 0;
}