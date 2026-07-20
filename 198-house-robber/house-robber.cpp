class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = nums[0], prev2 = 0;

        for(int i=1;i<nums.size();i++){
            int take = nums[i] + prev2;
            int not_take = prev;

            prev2 = prev;
            prev = max(take,not_take);
        }

        return prev;
    }
};