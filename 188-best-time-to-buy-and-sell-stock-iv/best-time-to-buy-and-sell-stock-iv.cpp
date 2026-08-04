class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));

        for(int i=n-1;i>=0;i--){
            for(int j=2*k-1;j>=0;j--){
                if(j%2==0){
                    dp[i][j] = max(-p[i]+dp[i+1][j+1],dp[i+1][j]);
                }else{
                    dp[i][j] = max(p[i]+dp[i+1][j+1],dp[i+1][j]);
                }
            }
        }

        return dp[0][0];
    }
};