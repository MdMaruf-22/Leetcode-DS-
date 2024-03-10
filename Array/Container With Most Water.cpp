class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int mx=0;
        while(l<r){
            int curr = min(height[l],height[r]) * (r-l);
            mx = max(mx,curr);
            if(height[l]<height[r]) l++;
            else r--;
        }
        return mx;
    }
};