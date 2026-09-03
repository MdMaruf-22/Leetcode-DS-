class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int tar = abs(nums[i]);
            int ind = tar -1;
            if(nums[ind]<0) ans.push_back(tar);
            else nums[ind] = -nums[ind];
        }
        return ans;
    }
};