#include<bits/stdc++.h>
using namespace std;
#define int long long

int fact(int n){
    if(n==1) return 1;
    return n*fact(n-1);
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    cout<<fact(t)<<endl;
}
