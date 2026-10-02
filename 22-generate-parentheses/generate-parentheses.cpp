class Solution {
public:
    void recur(vector<string>& ans, string& ds, int open, int close) {
        if (open == 0 && close == 0) {
            ans.push_back(ds);
            return;
        }

        if (open > 0) {
            ds.push_back('(');
            recur(ans, ds, open - 1, close);
            ds.pop_back();
        }

        if (close > open) {
            ds.push_back(')');
            recur(ans, ds, open, close - 1);
            ds.pop_back();
        }
        
    }


    vector<string> generateParenthesis(int n) {
        if(n==1) return {"()"};
        vector<string> ans;
        string ds;
        recur(ans,ds,n,n);
        return ans;
    }
};