#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string pattern)
{
    int m = pattern.length();
    vector<int> lps(m, 0);
    int len = 0;
    int i = 1;
    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

vector<int> kmpSearch(string text, string pattern)
{
    vector<int> result;
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = computeLPS(pattern);
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }
        if (j == m)
        {
            result.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return result;
}

int main()
{
    string text,pattern;
    cin >> text>>pattern;
    vector<int> ans = kmpSearch(text,pattern);
    //cout << ans << endl;
}