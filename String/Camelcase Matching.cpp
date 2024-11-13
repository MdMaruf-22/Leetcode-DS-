class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(auto str:queries){
            bool f = isMatch(str,pattern);
            ans.push_back(f);
        }
        return ans;
    }
    bool isMatch(string q,string p){
        int j=0;
        for(int i=0;i<q.size();i++){
            if(j<p.size() && q[i]==p[j]) j++;
            else if(isupper(q[i])) return false;
        }
        return j==p.size();
    }
};