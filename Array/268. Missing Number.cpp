class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        cout<<n<<endl;
        int sum = n*(n+1)/2;
        int x = 0;
        for(auto y:nums) x+=y;
        return sum-x; 
    }
};