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

    void insert(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool canFormWord(const string& word, int start, int count) {
        if (start == word.size()) return count >= 2;

        Node* node = root;
        for (int i = start; i < word.size(); ++i) {
            char ch = word[i];
            if (!node->containsKey(ch)) return false;
            node = node->get(ch);
            if (node->isEnd() && canFormWord(word, i + 1, count + 1)) {
                return true;
            }
        }
        return false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        root = new Node();
        for (const string& word : words) {
            insert(word);
        }

        vector<string> result;
        for (const string& word : words) {
            if (canFormWord(word, 0, 0)) {
                result.push_back(word);
            }
        }
        return result;
    }
};