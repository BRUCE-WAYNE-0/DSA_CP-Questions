class Solution {
public:
    int coinChange(vector<int>& nums, int k) {
        vector<int> prev(k + 1, -1);
        prev[0] = 0;

        for (int j = nums[0]; j <= k; j++) {
            if (prev[j - nums[0]] != -1) {
                prev[j] = 1 + prev[j - nums[0]];
            }
        }


        for (int i = 1; i < nums.size(); i++) {
            vector<int> curr(k + 1, -1);
            curr[0] = 0;

            for (int j = 0; j <= k; j++) {

                int not_take = prev[j];

                int take = -1;
                if (nums[i] <= j && curr[j - nums[i]] != -1) {
                    take = 1 + curr[j - nums[i]];
                }

                if (not_take == -1 && take == -1)
                    curr[j] = -1;
                else if (not_take == -1)
                    curr[j] = take;
                else if (take == -1)
                    curr[j] = not_take;
                else
                    curr[j] = min(not_take, take);
            }

            prev = curr;
        }

        return prev[k];
    }
};