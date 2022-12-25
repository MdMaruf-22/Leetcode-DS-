class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> vc;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=(target-nums[i]);
            if(mp.find(x)!=mp.end()){
                vc.push_back(i);
                vc.push_back(mp[x]);
                break;
            }
            mp.insert({nums[i],i});
        }
        return vc;
    }
};
