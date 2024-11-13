class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int left=0;long long sum=0;
        unordered_map<int,int> mp;
        for(int right=0;right<k;right++){
            mp[nums[right]]++;
            sum+=nums[right];
        }
        long long maxi = (mp.size()==k)?sum:0;
        for(int right=k;right<nums.size();right++){
            mp[nums[right]]++;
            sum += nums[right];
            mp[nums[right-k]]--;
            sum -= nums[right-k];
            if(mp[nums[right-k]]==0){
                mp.erase(nums[right-k]);
            }
            if(mp.size()==k) maxi = max(maxi,sum);
        }
        return maxi;
    }
};