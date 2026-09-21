class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> a;
        a.push_back(1);
        for(int num : nums) a.push_back(num);
        a.push_back(1);
        int n = a.size();
        vector<vector<int>> dp(n,vector<int>(n));
        // dp[i][j] = maxCoins from the ballon i to j.

        for (int len = 2; len < n; len++) {
            for (int i = 0; i + len < n; i++) {
                int j = i + len;

                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = max(
                        dp[i][j],
                        dp[i][k] +
                        dp[k][j] +
                        a[i] * a[k] * a[j]
                    );
                }
            }
        }
        return dp[0][n-1];
    }
};