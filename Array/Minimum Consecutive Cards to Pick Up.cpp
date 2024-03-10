class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int left=0,ans=INT_MAX;
        unordered_map<int,int> mp;
        for(int right=0;right<cards.size();right++){
            mp[cards[right]]++;
            while(mp[cards[right]]==2){
                ans = min(ans,right-left+1);
                mp[cards[left]]--;
                left++;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};