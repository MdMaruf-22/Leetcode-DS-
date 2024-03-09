class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        for(int i=1;i<=n;i++){
            for(auto t:times){
                int src=t[0],des=t[1],wt=t[2];
                if(dist[src]!=INT_MAX && dist[des] > dist[src] + wt){
                    dist[des] = dist[src] + wt;
                }
            }
        }
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            mx = max(mx, dist[i]);
        }
        return mx == INT_MAX ? -1 : mx;
    }
};