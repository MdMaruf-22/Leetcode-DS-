#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        vector<int> memo(n + 1, -1); 
        calc(n, ans, memo);
        return ans;
    }
};
void calc(int i, vector<int> &ans, vector<int> &memo) {
        if (i < 0) return;  
        if (memo[i] != -1) {
            ans[i] = memo[i];
            return;
        }
        calc(i - 1, ans, memo);
        ans[i] = countOnes(i);
        memo[i] = ans[i];
    }
    int countOnes(int num) {
        int count = 0;
        while (num > 0) {
            count += num & 1;  
            num >>= 1;  
        }
        return count;
    }
