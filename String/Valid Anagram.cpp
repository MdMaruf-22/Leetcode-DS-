class Solution {
public:
    bool isAnagram(string s, string t) {
        int chk[255]={0};
        int sz1=s.size(),sz2=t.size();
        if(sz1!=sz2) return false;
        for(int i=0;i<sz1;i++){
            chk[s[i]]+=1;
        }
        for(int i=0;i<sz2;i++){
            chk[t[i]]-=1;
        }
        for(int i=0;i<255;i++){
            if(chk[i]!=0) return false;
        }
        return true;
    }
};
