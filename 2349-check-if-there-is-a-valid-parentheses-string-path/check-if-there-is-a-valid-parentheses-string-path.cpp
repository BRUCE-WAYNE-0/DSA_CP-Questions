class Solution {
public:
    // bool dfs(vector<vector<char>>& grid,int i,int j,int cnt,int &m,int &n){
    //     if(grid[i][j] == '(') cnt++;
    //     else cnt--;
    //     if(i==m-1 && j==n-1 && cnt==0) return true;
    //     if(j+1 < n){
    //         if(dfs(grid,i,j+1,cnt,m,n)) return true;
    //     }
    //     if(i+1 < m){
    //         if(dfs(grid,i+1,j,cnt,m,n)) return true;
    //     }
    //     return false;
    // }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if (grid[0][0] != '(' || grid[m-1][n-1] != ')')
            return false;

        vector<vector<int>> prev(n,vector<int>(m + n, 0));
        vector<vector<int>> curr(n,vector<int>(m + n, 0));
        curr[0][1] = 1;

        for (int i = 0; i < m; i++) {
            if (i > 0) curr.assign(n, vector<int>(m+n, 0));
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;
                int change = (grid[i][j] == '(' ? 1 : -1);
                // From top
                if (i - 1 >= 0) {
                    for (int k = 0; k < m+n; k++) {
                        if (prev[j][k]) {
                            int nk = k + change;

                            if (nk >= 0 && nk < m+n)
                                curr[j][nk] = 1;
                        }
                    }
                }

                // From left
                if (j - 1 >= 0) {
                    for (int k = 0; k < m+n; k++) {
                        if (curr[j-1][k]) {
                            int nk = k + change;
                            if (nk >= 0 && nk < m+n)
                                curr[j][nk] = 1;
                        }
                    }
                }
            }
            prev = curr;
        }

        return prev[n-1][0];
    }
};