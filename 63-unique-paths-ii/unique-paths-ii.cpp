class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;
        vector<int> prev(n,0);
        bool obstruct = false;
        for(int i=0;i<m;i++){
            vector<int> curr(n,1);
            if(obstruct){
                curr[0] = 0;
            }else{
                if(obstacleGrid[i][0] == 1){
                    obstruct = true;
                    curr[0] = 0;
                }
            }

            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j] == 1){
                    curr[j] = 0;
                    continue;
                }
                curr[j] = curr[j-1] + prev[j];
            }

            prev = curr;
        }

        return prev[n-1];
    }
};