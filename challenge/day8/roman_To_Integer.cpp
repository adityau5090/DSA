// Leetcode problem No -> 13

#include <iostream>
#include <unordered_map>
using namespace std;
int romanToInt(string s)
{
    unordered_map<char, int> mp;

    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int current = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (mp[s[i]] < mp[s[i + 1]])
        {
            current -= mp[s[i]];
        }
        else
        {
            current += mp[s[i]];
        }
    }
    current += mp[s[s.length() - 1]];
    return current;
}
int main()
{
    string s = "MCMXCIV";
    cout<<romanToInt(s);
    return 0;
}