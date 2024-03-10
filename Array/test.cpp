#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
{
    vector<int> result;
    map<int, int> freqMap;
    for (int i = 0; i < k; i++)
    {
        if (nums[i] < 0)
            freqMap[nums[i]]++;
    }
    if (freqMap.empty())
        result.push_back(0);
    else
    {
        auto it = freqMap.begin();
        if (freqMap.size() >= x)
        {
            advance(it, x - 1);
            result.push_back(it->first);
        }
        else
        {
            result.push_back(0);
        }
    }
    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i - k] < 0)
        {
            freqMap[nums[i - k]]--;
            if (freqMap[nums[i - k]] == 0)
                freqMap.erase(nums[i - k]);
        }
        if (nums[i] < 0)
            freqMap[nums[i]]++;
        if (freqMap.empty())
            result.push_back(0);
        else
        {
            auto it = freqMap.begin();
            if (freqMap.size() >= x)
            {
                advance(it, x - 1);
                result.push_back(it->first);
            }
            else
            {
                result.push_back(0);
            }
        }
    }
    return result;
}

int main()
{
    int n,k,x;cin>>n>>k>>x;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    vector<int> ans = getSubarrayBeauty(vc,k,x);
    for(auto x:ans) cout<<x<<" ";
}