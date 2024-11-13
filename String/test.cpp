#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> computeLPS(string pattern) {
        int m = pattern.length();
        vector<int> lps(m, 0);
        int len = 0; // length of the previous longest prefix suffix
        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    vector<int> kmpSearch(string text, string pattern) {
        vector<int> result;
        int n = text.length();
        int m = pattern.length();
        vector<int> lps = computeLPS(pattern);
        int i = 0; // index for text[]
        int j = 0; // index for pattern[]
        while (i < n) {
            if (pattern[j] == text[i]) {
                j++;
                i++;
            }
            if (j == m) {
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && pattern[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return result;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> beautiful;
        vector<int> aIndices = kmpSearch(s, a);
        vector<int> bIndices = kmpSearch(s, b);
        for (int i : aIndices) {
            for (int j : bIndices) {
                if (abs(i - j) <= k) {
                    beautiful.push_back(i);
                    break;
                }
            }
        }
        sort(beautiful.begin(), beautiful.end());
        return beautiful;
    }
};
int main() {
    Solution solution;
    string s = "marufkjhmarkjmaruf";
    string a = "maruf";
    vector<int> indices = solution.kmpSearch(s, a);
    cout << "Occurrences of 'abc' in 'ababcababcabc': ";
    for (int index : indices) {
        cout << index << " ";
    }
    cout << endl;
    return 0;
}