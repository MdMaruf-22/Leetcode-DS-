#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    for(int i=0;i<n-1;i++){
        int mn = i;
        for(int j=i+1;j<n;j++){
            if (vc[j]<vc[mn]){
                mn=j;
            }
        }
        swap(vc[i],vc[mn]);
    }
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
