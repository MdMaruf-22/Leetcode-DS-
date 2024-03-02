class Solution {
private:
    vector<string> ans;

    void dfs(const string& s, const unordered_set<string>& wordSet, string st, int pos) {
        if (pos == s.size()) {
            ans.push_back(st);
            return;
        }
        st += " ";
        for (int i = pos; i < s.size(); i++) {
            string word = s.substr(pos, i + 1 - pos);
            if (wordSet.count(word)) {
                dfs(s, wordSet, st + word, i + 1);
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        for (int i = 0; i < s.size(); i++) {
            string word = s.substr(0, i + 1);
            if (wordSet.count(word)) {
                dfs(s, wordSet, word, i + 1);
            }
        }
        return ans;
    }
};