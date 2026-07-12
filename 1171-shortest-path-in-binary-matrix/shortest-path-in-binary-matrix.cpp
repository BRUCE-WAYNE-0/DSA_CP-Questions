class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(n,1e5));
        dist[0][0] = 1;
        q.push({1,{0,0}});


        int d_s[5] = {-1,0,1,0,-1}; // for side touching nodes
        int d_c[5] = {-1,1,1,-1,-1}; // for corner touching nodes

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int cost = p.first;
            int r = p.second.first;
            int c = p.second.second;

            for(int i=0;i<4;i++){
                if(r+d_s[i]>=0 && r+d_s[i]<n && c+d_s[i+1]>=0 && c+d_s[i+1]<n && grid[r+d_s[i]][c+d_s[i+1]]==0){
                    if(cost+1 < dist[r+d_s[i]][c+d_s[i+1]]){
                        dist[r+d_s[i]][c+d_s[i+1]] = cost+1;
                        q.push({cost+1,{r+d_s[i],c+d_s[i+1]}});
                    }
                }

                if(r+d_c[i]>=0 && r+d_c[i]<n && c+d_c[i+1]>=0 && c+d_c[i+1]<n && grid[r+d_c[i]][c+d_c[i+1]]==0){
                    if(cost+1 < dist[r+d_c[i]][c+d_c[i+1]]){
                        dist[r+d_c[i]][c+d_c[i+1]] = cost+1;
                        q.push({cost+1,{r+d_c[i],c+d_c[i+1]}});
                    }
                }
            } 
        }
        if(dist[n-1][n-1] == 1e5) return -1;
        return dist[n-1][n-1];
    }
};