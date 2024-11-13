class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            vector<int> nums = grid[i];
            int lo=0,hi=nums.size()-1;
            while(lo<=hi){
                int mid = lo + (hi-lo)/2;
                if(nums[mid]<0){
                    hi = mid-1;
                }
                else lo = mid+1;
            }
            cnt += nums.size() - lo;
        }
        return cnt;
    }
};