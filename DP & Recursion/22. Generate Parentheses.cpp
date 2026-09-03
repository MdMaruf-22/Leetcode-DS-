class Solution {
public:
vector<string> vc;
void calc(string& s,int open,int close){
    if(open==0 and close==0){
        vc.push_back(s);
        return;
    }
    if(open>0){
        s.push_back('(');
        calc(s,open-1,close);
        s.pop_back();
    }
    if(close>0 && open<close){
        s.push_back(')');
        calc(s,open,close-1);
        s.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        string s = "";
    calc(s,n,n);
    return vc;
    }
};