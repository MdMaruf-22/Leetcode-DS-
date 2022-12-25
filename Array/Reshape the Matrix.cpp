class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row=mat.size();
        int col=mat[0].size();
        if(row*col!=r*c) return mat;
        vector<vector<int>> vc(r,vector<int>(c,0));
        for(int i=0;i<row*col;i++){
            vc[i/c][i%c]=mat[i/col][i%col];
        }
        return vc;
    }
};
