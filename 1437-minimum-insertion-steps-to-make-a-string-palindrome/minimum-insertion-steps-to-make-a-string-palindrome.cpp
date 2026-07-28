class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])  curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[m];
    }

    int longestPalindrome(string s) {
        string rev = s;
        reverse(s.begin(),s.end());
        return longestCommonSubsequence(s,rev);
    }

    int minInsertions(string s) {
        int lpl = longestPalindrome(s);
        return s.size()-lpl;
    }
};