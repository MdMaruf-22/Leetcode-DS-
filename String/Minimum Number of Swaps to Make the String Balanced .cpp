class Solution {
public:
    int minSwaps(string s) {
        int open = 0,swap=0;
        for(char c:s){
            if(c=='[') open++;
            else if(open>0) open--;
        }
        swap = (open+1) >> 1;//swap = (opn+1)/2 (one swap to change);
        return swap;
    }
};