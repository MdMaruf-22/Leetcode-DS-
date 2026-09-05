#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)



void merge(vector<int>& vc, int left, int mid, int right){
    vector<int> tmp;
    int i=left,j=mid+1;
    while(i<=mid && j<=right){
        if(vc[i]<=vc[j]){
            tmp.push_back(vc[i]);
            i++;
        }
        else {
            tmp.push_back(vc[j]);
            j++;
        }
    }
    while(i<=mid){
        tmp.push_back(vc[i]);
        i++;
    }
    while(j<=right){
        tmp.push_back(vc[j]);
        j++;
    }
    for(int x=0;x<tmp.size();x++) vc[left+x] =tmp[x];
}

void mergeSort(vector<int>& vc,int left, int right,int pass){
    if(left>=right) return;
    // Print current subarray
    for(int k = 0; k < pass; k++)
        cout << "    ";

    cout << "[ ";
    for(int k = left; k <= right; k++)
        cout << vc[k] << " ";
    cout << "]\n";
    int mid = left + (right-left)/2;
    mergeSort(vc,left,mid,pass+1);
    mergeSort(vc,mid+1,right,pass+1);
    merge(vc,left,mid,right);
}


void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    mergeSort(vc,0,n-1,0);
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
