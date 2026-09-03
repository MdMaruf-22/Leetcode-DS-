#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
int findLo(vector<int>& vc,int target){
    int l=0,r=vc.size()-1;
    while(l<=r){
        int mid=l + (r-l)/2;
        if(vc[mid]>=target) r=mid-1;
        else l=mid+1;
    }
    return l;
}
int findHi(vector<int>& vc,int target){
    int l=0,r=vc.size()-1;
    while(l<=r){
        int mid=l + (r-l)/2;
        if(vc[mid]<=target) l=mid+1;
        else r=mid-1;
    }
    return l-1;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    int ans1 = findLo(vc,k);
    int ans2 = findHi(vc,k);
    //cout<<ans1<<" "<<ans2<<endl;
    if(ans1>=vc.size() || vc[ans1]!=k) cout<<-1<<" "<<-1<<endl;
    else if(ans2<0 || vc[ans2]!=k) cout<<-1<<" "<<-1<<endl; 
    else cout<<ans1<<" "<<ans2<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
