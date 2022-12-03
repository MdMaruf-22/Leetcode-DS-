class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int mx=0,mn=arr[0];
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(arr[i]<mn){
                mn=min(mn,arr[i]);
                //cout<<"Min: "<<mn;
            }
            else if(arr[i]>mn){
                int dif=arr[i]-mn;
                mx=max(mx,dif);
            }
        }
        return mx;
    }
};
