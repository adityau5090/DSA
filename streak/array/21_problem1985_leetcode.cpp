// Find The Kth Largest Intger In Array

#include <bits/stdc++.h>
using namespace std;

bool isGreater(string a, string b)
{
    if (a.size() != b.size())
    {
        return a.size() > b.size();
    }
    return a > b;
}

string kthLargestNumber(vector<string> &arr, int k)
{
    int n = arr.size();

    vector<bool> used(n, false);

    string largest;

    for (int count = 0; count < k; count++)
    {
        int maxIndex = -1;
        for (int i = 0; i < n; i++)
        {
            if (used[i])
                continue;

            if (maxIndex == -1 || isGreater(arr[i], arr[maxIndex]))
            {
                maxIndex = i;
            }
        }
        used[maxIndex] = true;
        largest = arr[maxIndex];
    }
    return largest;
}

string kthLargestNumber2(vector<string> &arr, int k)
{
    sort(arr.begin(), arr.end(),
         [](const string &a, const string &b)
         {
             if (a.size() != b.size())
             {
                 return a.size() > b.size();
             }

             return a > b;
         });

    return arr[k - 1];
}

int main()
{

    vector<string> arr = {"2", "21", "12", "1"};
    int k = 3;
    cout << k << "th Largest : " << kthLargestNumber2(arr, 3);

    return 0;
}