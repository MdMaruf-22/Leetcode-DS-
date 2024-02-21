struct Node {
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
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

class Trie {
private: 
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); ++i) {
            char ch = word[i];
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    string longestCommonPrefix() {
        string prefix = "";
        Node* node = root;
        while (true) {
            // Check if current node has only one link (if so, add to prefix)
            int count = 0;
            char nextChar;
            for (int i = 0; i < 26; ++i) {
                if (node->links[i] != nullptr) {
                    count++;
                    nextChar = 'a' + i;
                }
            }
            if (count == 1 && !node->isEnd()) {
                prefix.push_back(nextChar);
                node = node->get(nextChar);
            } else {
                break;
            }
        }
        return prefix;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        Trie trie;
        for (const auto& word : strs) {
            trie.insert(word);
        }
        return trie.longestCommonPrefix();
    }
};