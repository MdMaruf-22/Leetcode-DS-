#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

int binarySearch(vector<int>& vc,int target){
    int left = 0,right = vc.size()-1;
    while(left<=right){
        int mid = left + (right-left) / 2;
        if(vc[mid]<target) left = mid +1;
        else right = mid-1;
    }
    return left;
}


int lengthOfLIS(vector<int>& nums) {
    vector<int> subseq;
    subseq.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        int index = binarySearch(subseq,nums[i]);
        if(index==subseq.size()) subseq.push_back(nums[i]);
        else subseq[index] = nums[i];
    }
    return subseq.size();
}

void solve()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout<<lengthOfLIS(nums)<<endl;
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
