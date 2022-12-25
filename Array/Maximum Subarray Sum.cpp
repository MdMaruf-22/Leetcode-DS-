class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int mx=INT_MIN,sum=0;
        for(auto x:nums){
            sum+=x;
            mx=max(mx,sum);
            if(sum<0) sum=0;
        }
        return mx;
    }
};
