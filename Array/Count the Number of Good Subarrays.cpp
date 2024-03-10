#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        long long result = 0;
        int pairs = 0;

        // Loop through the array using two pointers (left and right).
        for (int left = 0, right = 0; right < nums.size(); right++) {
            // Increment the count of the current number in the map and add to the pairs count.
            pairs += counts[nums[right]]++;

            // If the number of pairs is greater than or equal to k, we have a good subarray.
            while (pairs >= k) {
                // Add the count of subarrays ending at the current right pointer position to the result.
                result += nums.size() - right;
                // Decrease the pairs count by removing the contribution of the leftmost element.
                pairs -= --counts[nums[left++]];
            }
        }
        return result; // Return the total count of good subarrays.
    }
};
