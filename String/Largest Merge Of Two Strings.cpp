/*
Time complexity here: O(n*m);
*/

class Solution {
public:
    string largestMerge(string word1, string word2) {
        if(word1.size()==0 || word2.size()==0) return word1+word2;
        if(word1>word2){
            return word1[0]+largestMerge(word1.substr(1),word2);
        }
        else return word2[0]+largestMerge(word1,word2.substr(1));
    }
};
/*
Time complexity here: O(n+m);
class Solution {
public:
    string largestMerge(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int i = 0,j=0;
        string res = "";
        while(i<n || j<m){
            bool flag = word1.substr(i)>word2.substr(j);
            if(flag) res+=word1[i++];
            else res+=word2[j++];
        }
        res += word1.substr(i);
        res += word2.substr(j);
        return res;
    }
};
*/
