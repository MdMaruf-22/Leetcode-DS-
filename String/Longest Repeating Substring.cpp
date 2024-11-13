#include<bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string pat){
    vector<int> lps(pat.size());
    int len=0;
    lps[len]=0;
    int i=1;
    while(i<pat.size()){
        if(pat[len]==pat[i]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len!=0) len = lps[len-1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
int KMP(string text){
    vector<int> lps = computeLPS(text);
    int m = text.size();
    int mx  = INT_MIN;
    for(int i=0;i<m;i++){
        mx = max(mx,lps[i]);
    }
    return mx;
}
int main(){
    string text;
    cin>>text;
    int ans = KMP(text);
    cout<<ans<<endl;
}