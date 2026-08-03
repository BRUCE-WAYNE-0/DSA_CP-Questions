class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<int> prev(2,0);
        vector<int> curr(2); 

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(j){
                    curr[j] = max(prev[1],prev[0]-p[i]);
                }else{
                    curr[j] = max(p[i]+prev[1],prev[0]);
                }
            }
            prev = curr;
        }

        return prev[1];
    }
};