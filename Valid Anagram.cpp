class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vc(26,0);
        for(auto i:s) vc[i-'a']++;
        for(auto i:t){
            if(vc[i-'a']==0) return false;
            vc[i-'a']--;
        }
        for(auto x:vc){
            if(x>=1) return false;
        }
        return true;
    }
};
