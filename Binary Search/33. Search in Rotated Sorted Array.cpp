class Solution {
public:
    int bianrySearch(vector<int>& nums, int target,int low,int high){
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        // int low=0,high=nums.size()-1;
        // while(low<high){
        //     int mid = low + (high-low)/2;
        //     if(nums[mid]>nums[high]) low = mid + 1;
        //     else high = mid;
        // }
        // int piv = low;
        // int firstLow=0,firstHigh=piv-1;
        // int lastLow=piv,lastHigh=nums.size()-1;
        // int chkFirst = bianrySearch(nums,target,firstLow,firstHigh);
        // int chkLast = bianrySearch(nums,target,lastLow,lastHigh);
        // if(chkFirst!=-1) return chkFirst;
        // if(chkLast!=-1) return chkLast;
        // return -1;

        int low = 0, high=nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target) return mid;
            //Left is sorted
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<nums[mid]) high=mid-1;
                else low = mid+1;
            }
            //Right half is sorted
            else{
                if(target>nums[mid] && target<=nums[high]) low=mid+1;
                else high = mid-1;
            }
        }
        return -1;
    }
};