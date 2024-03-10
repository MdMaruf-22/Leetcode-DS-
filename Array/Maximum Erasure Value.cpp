class Solution {
public:
    int maximumUniqueSubarray(std::vector<int>& nums) {
        unordered_map<int,int> mp;
        int left = 0;
        long long int ans = 0, sum = 0;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            mp[nums[right]]++;
            while(mp[nums[right]] == 2){
                sum -= nums[left];
                mp[nums[left]]--;
                left++;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};