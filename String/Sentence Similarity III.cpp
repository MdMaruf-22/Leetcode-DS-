class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = split(sentence1, ' ');
        vector<string> words2 = split(sentence2, ' ');
        if(words1.size()<words2.size()) swap(words1,words2);
        int len1 = words1.size();
        int len2 = words2.size();
        int pref=0,suff=0;
        while(pref<len2 && words1[pref] == words2[pref]) pref++;
        while(suff<len2 && words1[len1 - 1 - suff] == words2[len2 - 1 -suff]) suff++;
        return pref+suff>=len2;
    }
    vector<string> split(string& s, char delimiter) {
        stringstream stream(s);
        string item;
        vector<string> result;
        while (getline(stream, item, delimiter)) {
            result.emplace_back(item);
        }

        return result;
    }
};