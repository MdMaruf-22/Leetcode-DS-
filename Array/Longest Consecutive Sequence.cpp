class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto x:nums) s.insert(x);
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            if(s.find(val-1)==s.end()){
                int next = nums[i];
                while(s.find(next)!=s.end()) next++;
                ans = max(ans,next-nums[i]);
            }
        }
        return ans;
    }
};