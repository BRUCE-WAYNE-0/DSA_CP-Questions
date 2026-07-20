class Solution {
public:
    int solve(int start, int end, vector<int>& nums){
        int prev = 0;
        int mx = 0;

        for(int i=start; i<=end; i++){
            int temp = max(mx, prev + nums[i]);
            prev = mx;
            mx = temp;
        }
        return mx;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return max(solve(0, nums.size() - 2, nums), solve(1, nums.size() - 1, nums));     
    }
};