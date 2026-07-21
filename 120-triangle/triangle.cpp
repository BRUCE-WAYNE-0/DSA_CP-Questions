class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 1) return triangle[0][0];
        vector<int> prev;
        prev.push_back(triangle[0][0] + triangle[1][0]);
        prev.push_back(triangle[0][0] + triangle[1][1]);

        for(int i=2;i<triangle.size();i++){
            vector<int> curr(i+1);
            curr[0] = prev[0] + triangle[i][0];
            curr[i] = prev[i-1] + triangle[i][i];
            for(int j=1;j<i;j++){
                curr[j] = triangle[i][j] + min(prev[j-1],prev[j]);
            }
            prev = curr;
        }
        int mini = INT_MAX;
        for(auto val : prev) mini = min(mini,val);
        return mini;
    }
};