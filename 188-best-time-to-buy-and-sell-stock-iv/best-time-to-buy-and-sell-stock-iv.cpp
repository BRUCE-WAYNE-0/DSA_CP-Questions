class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        vector<vector<int>> prev(2,vector<int>(k+1,0));
        vector<vector<int>> curr(2,vector<int>(k+1));

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                curr[j][0] = 0;
                for(int cap=1;cap<=k;cap++){
                    if(j){
                        curr[j][cap] = max(prev[1][cap],prev[0][cap]-p[i]);
                    }else{
                        curr[j][cap] = max(prev[0][cap],prev[1][cap-1]+p[i]);
                    }
                }
            }
            prev = curr;
        }

        return prev[1][k];
    }
};