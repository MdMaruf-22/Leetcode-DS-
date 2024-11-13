class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int longestUncommonLength = -1;
      
        for (int i = 0, j = 0, n = strs.size(); i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (i == j) continue;
                if (isSubsequence(strs[j], strs[i])) break;
            }
            if (j == n) longestUncommonLength = max(longestUncommonLength, (int)strs[i].size());
        }
        return longestUncommonLength;
    }

private:
    bool isSubsequence(const string& a, const string& b) {
        int indexB = 0;
        for (int i = 0; i < a.size() && indexB < b.size(); ++i) {
            if (a[i] == b[indexB]) ++indexB;
        }
        return indexB == b.size();
    }
};
