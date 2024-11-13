class Solution {
public:
    int getMinSwaps(string num, int k) {
        string next = num;
        while(k--){
            next_permutation(begin(next),end(next));
        }
        return count(num,next);
    }
    int count(string num, string next){
        int cnt = 0;
        for(int i=0;i<num.size();i++){
            int j=i;
            while(num[i]!=next[j]){
                j++;
            }
            while(i<j){
                swap(next[j],next[j-1]);
                j--;
                cnt++;
            }
        }
        return cnt;
    }
};