class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        vector<bool> prev(m+1,false);
        vector<bool> curr(m+1);
        prev[0] = true;
        bool flag = true;
        for(int i=1;i<=n;i++){
            if(p[i-1] != '*') flag = false;
            curr[0] = flag;
            for(int j=1;j<=m;j++){
                if(p[i-1] == s[j-1] || p[i-1] == '?') curr[j] = prev[j-1];
                else if(p[i-1]=='*') curr[j] = curr[j-1] || prev[j];
                else curr[j] = false;
            }
            prev = curr;
        }
        return prev[m];
    }
};