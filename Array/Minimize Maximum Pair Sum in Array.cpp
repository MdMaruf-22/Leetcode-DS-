class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int left=0,mx = INT_MIN;
        for(int right=0;right<nums.size()/2;right++){
            int sum = nums[right] + nums [nums.size()-right-1];
            mx = max(mx,sum);
        }
        return mx;
    }
};