#include <vector>

using namespace std;

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = groups.size(); // Number of groups
        int m = nums.size(); // Number of elements in nums
        int groupIndex = 0; // Index to track the current group we are looking for
        int numsIndex = 0; // Index to track the current position in nums

        while (groupIndex < n && numsIndex < m) {
            vector<int>& group = groups[groupIndex]; // Current group
            int groupSize = group.size(); // Size of the current group

            // Check if the current group matches the elements starting from numsIndex
            bool match = true;
            for (int i = 0; i < groupSize; ++i) {
                if (numsIndex + i >= m || nums[numsIndex + i] != group[i]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                // Move numsIndex to the end of the current group
                numsIndex += groupSize;
                // Move to the next group
                groupIndex++;
            } else {
                // If no match is found, move numsIndex to the next position
                numsIndex++;
            }
        }

        // Check if all groups have been found and are disjoint
        return groupIndex == n;
    }
};


/*

class Solution {
public:
 
    vector<int> construct_lps(vector<int>& nums){

        vector<int> lps(nums.size() , 0) ;
        int len = 0 , i = 1 ;

        while(i<nums.size()){
            if(nums[len] == nums[i]){
                len++ ;
                lps[i] = len ;
                i++ ;
            }

            else{

                if(len != 0){
                    len = lps[len-1] ;
                }
                else i++ ;
            }
        }
        return lps ;
    }

    bool kmp(vector<vector<int>>& groups, vector<int>& nums){
        int i = 0 ;
        vector<int> lps = construct_lps(nums) ;
        for(auto group : groups){
            int j = 0 ;
            while(i<nums.size() && j<group.size()){
                if(nums[i] == group[j]){
                    j++ ;
                    i++ ;
                }
                else{
                    if(j != 0) j = lps[j-1] ;
                    else i++ ;
                }
            }
           if(j<group.size() && i == nums.size()) return false ;
        }
        return true ;
    }

    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        return kmp(groups,nums) ;
    }
};

*/