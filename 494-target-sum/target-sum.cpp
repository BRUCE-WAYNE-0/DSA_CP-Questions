class Solution {
public:
    const int MOD = 1e9 + 7;
    int findWays(vector<int> &nums,int k){
        int n = nums.size();
        vector<int> prev(k+1,0);

        if(nums[0]==0) prev[0] = 2;
        else prev[0] = 1;

        if(nums[0]!=0 && nums[0]<=k) prev[nums[0]] = 1;

        for(int i=1;i<n;i++){
            vector<int> curr(k+1,0);
            for(int j=0;j<=k;j++){
                int not_take = prev[j];
                int take = 0;
                if(nums[i]<=j) take = prev[j - nums[i]];

                curr[j] = (take + not_take)%MOD;
            }
            prev = curr;
        }
        return prev[k];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0, n = nums.size();
        for(auto it : nums) sum += it;
        if((sum-target)%2 != 0 || sum-target < 0) return 0;
        return findWays(nums,(sum-target)/2);
    }
};