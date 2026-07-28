class Solution {
public:
    int lcs(string s1,string s2){
        int n = s1.size(), m = s2.size();
        vector<int> prev(m+1,0);
        for(int i=1;i<=n;i++){
            vector<int> curr(m+1,0);
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(curr[j-1],prev[j]);
            }
            prev = curr;
        }
        return prev[m];
    }

    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        return lcs(s,s2);
    }
};