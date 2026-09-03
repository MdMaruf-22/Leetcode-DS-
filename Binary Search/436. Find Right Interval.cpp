#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n;cin>>n;
    vector<int> st(n),en(n);
    for(int i=0;i<n;i++){
        cin>>st[i]>>en[i];
    }
    vector<pair<int,int>> pr;
    for(int i=0;i<n;i++){
        pr.push_back({st[i],i});
    }
    sort(pr.begin(),pr.end());
    for(int i=0;i<n;i++){
        int tar = en[i];
        int ans=-1;
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(pr[mid].first>=tar){
                ans = pr[mid].second;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        cout<<ans<<" ";
    }
    cout<<endl;
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
