#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

class Solution {
public:
    vector<vector<int>> dp;
    vector<int> calc(int row){
        if(row < dp.size()) return dp[row];
        if(row==0) return {1};
        vector<int> prevRow = calc(row-1);
        vector<int> currentRow(row + 1,1);
        for(int i=1;i<row;i++){
            currentRow[i] = prevRow[i-1] + prevRow[i];
        }
        dp.push_back(currentRow);
        return currentRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for(int i=0;i<numRows;i++){
            vector<int> row = calc(i);
            triangle.push_back(row);
        }
        return triangle;
    }
};
