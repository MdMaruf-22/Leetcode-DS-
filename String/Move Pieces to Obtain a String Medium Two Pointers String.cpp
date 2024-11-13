class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size(),m=target.size();
        int i=0,j=0;
        while(i<n || j<m){
            while(i<n && start[i]=='_') i++;
            while(j<m && target[j]=='_') j++;
            if(i==n || j==m) break;
            if(start[i]==target[j]){
                if(start[i]=='L' && i<j) return false;
                if(start[i]=='R' && i>j) return false;
            }
            else return false;
            i++;
            j++;
        }
        return i==n && j==m;
    }
};