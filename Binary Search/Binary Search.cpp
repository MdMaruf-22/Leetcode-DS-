class Solution {
public:

    int check(int low, int high,int target, vector<int>& nums){
        if(low>high) return -1;
        int mid = low + (high-low)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) return check(mid+1,high,target,nums);
        else return check(low,mid-1,target,nums);
    }
    int search(vector<int>& nums, int target) {
        // Iterative
        // int low=0,high=nums.size()-1;
        // while(low<=high){
        //     int mid = low + (high-low)/2;
        //     if(nums[mid]==target) return mid;
        //     else if(nums[mid]<target) low=mid+1;
        //     else high=mid-1;
        // }
        // return -1;

        //Recursive 
        int ans = check(0,nums.size()-1,target,nums);
        return ans;

    }
};