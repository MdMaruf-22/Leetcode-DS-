class Solution {
private:
    struct Node {
        Node* links[26];
        bool flag = false;

        bool containsKey(char ch) {
            return (links[ch - 'a'] != nullptr);
        }

        void put(char ch, Node* node) {
            links[ch - 'a'] = node;
        }

        Node* get(char ch) {
            return links[ch - 'a'];
        }

        void setEnd() {
            flag = true;
        }

        bool isEnd() {
            return flag;
        }
    };

    Node* root;

    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) return false;
            node = node->get(ch);
        }
        return node->isEnd();
    }

    vector<string> ans;

    void solve(string& s, string st, int pos) {
        if (pos == s.size()) {
            ans.push_back(st);
            return;
        }
        st += " ";
        for (int i = pos; i < s.size(); i++) {
            if (search(s.substr(pos, i + 1 - pos))) {
                solve(s, st + s.substr(pos, i + 1 - pos), i + 1);
            }
        }
    }

public:
    Solution() {
        root = new Node();
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto word : wordDict) {
            insert(word);
        }
        for (int i = 0; i < s.size(); i++) {
            if (search(s.substr(0, i + 1))) {
                solve(s, s.substr(0, i + 1), i + 1);
            }
        }
        return ans;
    }
};