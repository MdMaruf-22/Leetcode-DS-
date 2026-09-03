class Solution {
public:
    vector<vector<int>> ans;
    void calc(int ind, vector<int>& nums,vector<int>& sub){
        if(ind==nums.size()){
            ans.push_back(sub);
            return;
        }
        //Include
        sub.push_back(nums[ind]);
        calc(ind+1,nums,sub);
        //Backtrack
        sub.pop_back();
        ///Not include
        calc(ind+1,nums,sub);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        calc(0,nums,sub);
        return ans;
    }
};