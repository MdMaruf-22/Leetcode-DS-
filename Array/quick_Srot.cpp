#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)


int partition(vector<int>& nums, int left, int right){
    int mid = left + (right-left)/2;
    int pivot = nums[mid];
    int i = left,j=right;
    while(i<=j){
        while(nums[i]<pivot) i++;
        while(nums[j]>pivot) j--;
        if(i<=j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
    return i;
}


void quickSort(vector<int>& nums, int left, int right){
    if(left>=right) return;
    int index  = partition(nums , left , right);
    quickSort(nums,left,index-1);
    quickSort(nums,index,right);
}

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    quickSort(vc,0,n);
    for(auto x:vc) cout<<x<<" ";
    
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
