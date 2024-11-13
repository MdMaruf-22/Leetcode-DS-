class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int left = 0, right = removable.size();
        while(left<right){
            int mid = (left + right + 1) / 2;
            if(check(s,p,removable,mid)){
                left = mid;
            }
            else right = mid-1;
        }
        return left;
    }
    bool check(string& s, string& p, vector<int>& removable, int mid){
        int sLen = s.size();
        int pLen = p.size();
        int i=0,j=0;
        unordered_set<int> st;
        for(int k=0;k<mid;k++) st.insert(removable[k]);
        while(i<sLen && j<pLen){
            if(st.count(i) == 0 && s[i]==p[j]) j++;
            i++;
        }
        return j == pLen;
    }
};