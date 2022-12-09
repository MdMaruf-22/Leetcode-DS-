class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++){
            int cnt=0;unordered_set<int> st;
            for(int j=0;j<col;j++){
                if(board[i][j]=='.') continue;
                st.insert(board[i][j]);
                cnt++;
            }
            if(st.size()!=cnt) return false;
        }
        for(int i=0;i<col;i++){
            int cnt=0;unordered_set<int> st;
            for(int j=0;j<row;j++){
                if(board[j][i]=='.') continue;
                st.insert(board[j][i]);
                cnt++;
            }
            if(st.size()!=cnt) return false;
        }
        for(int i=0;i<row;i+=3){
            for(int j=0;j<col;j+=3){
                int cnt=0;unordered_set<int> st;
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(board[k][l]=='.') continue;
                        st.insert(board[k][l]);
                        cnt++;
                    }
                }
                if(st.size()!=cnt) return false;
            }
        }
        return true;
    }
};
