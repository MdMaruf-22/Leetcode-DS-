class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> vc(26,0);
        for(int i=0;s[i]!='\0';i++) vc[s[i]-'a']++;
        for(int i=0;i<s.size();i++){
            if(vc[s[i]-'a']==1) return i;
        }
        return -1;
    }
};
