struct Node{
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch,Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(char ch:word){
            if(!node->containsKey(ch)){
                node->put(ch,new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        return dfs(word,root,0);
    }
    bool dfs(const string& word,Node* node, int index){
        if(index == word.size()){
            return node->isEnd();
        }
        char ch = word[index];
        if(ch == '.'){
            for(int i=0;i<26;i++){
                if(node->links[i]!=nullptr && dfs(word,node->links[i],index+1)){
                    return true;
                }
            }
            return false;
        }
        else{
            if(!node->containsKey(ch)) return false;
            return dfs(word,node->get(ch),index+1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */