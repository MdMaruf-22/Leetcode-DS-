class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        for (int right = 0, left = 0, product = 1; right < nums.size(); ++right) {
            product *= nums[right];
            while (left <= right && product >= k) {
                product /= nums[left++];
            }
            count += right - left + 1;
        }
        return count;
    }
};
