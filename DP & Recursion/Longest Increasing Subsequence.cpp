#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
vector<int> dp(3001,-1);
int calc(int endIndex,vector<int>& nums){
    if(dp[endIndex]!=-1) return dp[endIndex];
    int ans = 1;
    for(int i=0;i<endIndex;i++){
        if(nums[endIndex] > nums[i]){
            ans = max(ans , calc(i,nums) + 1);
        }
    }
    return ans;
}

int lengthOfLIS(vector<int>& nums) {
    int ans = 1;
    for(int i=0;i<nums.size();i++){
        ans = max(ans, calc(i,nums) );
    }
    return ans;
}
void solve()
{   
    vector<int> vc = {8,9,2,5,3,7,101,18};
    int ans = lengthOfLIS(vc);
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
