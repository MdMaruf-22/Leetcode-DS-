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
        dfs(root, prefix);
        return prefix;
    }
    
    void dfs(Node* node, string& prefix) {
        // Base case: if the node is an end node or has more than one child, return
        if (node->isEnd() || countChildren(node) > 1) {
            return;
        }
        
        // Find the child node
        Node* nextNode = nullptr;
        for (int i = 0; i < 26; ++i) {
            if (node->links[i] != nullptr) {
                nextNode = node->links[i];
                prefix.push_back('a' + i);
                break;
            }
        }
        
        // Recur for the child node
        dfs(nextNode, prefix);
    }
    
    int countChildren(Node* node) {
        int count = 0;
        for (int i = 0; i < 26; ++i) {
            if (node->links[i] != nullptr) {
                count++;
            }
        }
        return count;
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