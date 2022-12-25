class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> vc(26,0);
        int x=magazine.size();
        for(int i=0;i<x;i++) vc[magazine[i]-'a']++;
        for(int i=0;i<ransomNote.size();i++){
            if(vc[ransomNote[i]-'a']==0) return false;
            vc[ransomNote[i]-'a']--;
        }
        return true;
    }
};
