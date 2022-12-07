class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vc;
        for(int i=0;i<numRows;i++){
            vector<int> tmp(i+1,1);
            for(int j=1;j<i;j++){
                tmp[j]=vc[i-1][j-1]+vc[i-1][j];
            }
            vc.push_back(tmp);
        }
        return vc;
    }
};
