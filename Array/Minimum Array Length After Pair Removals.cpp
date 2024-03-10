class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        map<int,int> mp;
        for(auto x:nums) mp[x]++;
        priority_queue<int> maxHeap;
        for(auto x:mp) maxHeap.push(x.second);
        int ans = nums.size();
        while(maxHeap.size()>1){
            int top1 = maxHeap.top();
            maxHeap.pop();
            int top2 = maxHeap.top();
            maxHeap.pop();
            --top1;--top2;
            if(top1>0) maxHeap.push(top1);
            if(top2>0) maxHeap.push(top2);
            ans-=2;
        }
        return ans;
    }
};