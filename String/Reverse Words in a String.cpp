class Solution {
public:
    string reverseWords(string s) {
        int start=0,end=0,size = s.size();
        while(start<size){
            while(s[start]==' ' && start<size) start++;
            if(start<size){
                if(end!=0){
                    s[end]=' ';
                    ++end;
                }
                int tmp = start;
                while(tmp<size && s[tmp]!=' '){
                    s[end++] = s[tmp++];
                }
                reverse(s.begin()+end-(tmp-start),s.begin()+end);
                start=tmp;
            }
        }
        s.erase(s.begin()+end,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};