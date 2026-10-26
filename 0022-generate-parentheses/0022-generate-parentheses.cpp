class Solution {
public:
    void solve(string s,int open,int close,vector<string> &ans,int n){
        if(open == n && close == n){
            ans.push_back(s);
            return;
        }
        if (open <= n){
            string s1 = s;
            s1.push_back('(');
            solve(s1,open+1,close,ans,n);
        }
        if (close < open){
            string s1 = s;
            s1.push_back(')');
            solve(s1,open,close+1,ans,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        int open = 0;
        int close = 0;
        vector<string> ans;
        solve(s,open,close,ans,n);
        return ans;
    }
};