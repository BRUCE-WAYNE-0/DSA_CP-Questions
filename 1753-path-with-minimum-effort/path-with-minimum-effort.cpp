class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        if(m==1 && n==1) return 0;

        vector<vector<int>> efforts(m,vector<int>(n,1e9));
        using pii = pair<int, pair<int, int>>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0,{0,0}});
        int d[5] = {-1,0,1,0,-1};


        while(!q.empty()){
            auto p = q.top();
            q.pop();
            int eff = p.first;
            int r = p.second.first;
            int c = p.second.second;
            if (r == m - 1 && c == n - 1) {
                return eff;
            }
            if (eff > efforts[r][c]) {
                continue;
            }
            for(int i=0;i<4;i++){
                if(r+d[i]>=0 && r+d[i]<m && c+d[i+1]>=0 && c+d[i+1]<n){
                    int diff = max(eff,abs(heights[r][c]-heights[r+d[i]][c+d[i+1]]));
                    if(diff<efforts[r+d[i]][c+d[i+1]]){
                        efforts[r+d[i]][c+d[i+1]] = diff;
                        q.push({diff,{r+d[i],c+d[i+1]}});
                    }
                }
            }
        }
        return 0;
    }
};