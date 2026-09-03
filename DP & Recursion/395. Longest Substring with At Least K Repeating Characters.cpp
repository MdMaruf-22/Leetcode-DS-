#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calcUniq(string s, int k)
    {
        map<char, int> mp;
        for (auto x : s)
            mp[x]++;
        bool flag = true;
        for (auto x : mp)
        {
            if (x.second < k)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return s.size();
        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] < k)
            {
                maxLen = max(maxLen, longestSubstring(s.substr(start, i - start), k));
                start = i + 1;
            }
        }
        maxLen = max(maxLen, longestSubstring(s.substr(start), k));
        return maxLen;
    }
    int longestSubstring(string s, int k)
    {
        return calcUniq(s, k);
    }
};