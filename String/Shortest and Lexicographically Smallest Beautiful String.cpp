class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0,len=0,cnt=0;
        string res = "";
        for(int right=0;right<s.size();right++){
            if(s[right]=='1') cnt++;
            while(cnt>k || (s[left]=='0' && left<right)){
                cnt -= s[left++]=='1';
            }
            string sub = s.substr(left,right-left+1);
            if(cnt==k && (res.empty() || right-left + 1 < res.size() || (right-left+1 == res.size() && sub<res))) res = sub;
        }
        return res;
    }
};