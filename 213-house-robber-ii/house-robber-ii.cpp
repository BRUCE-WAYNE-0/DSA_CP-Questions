class Solution {
public:
    int rob1(vector<int>& nums) {
        int prev = nums[0], prev2 = 0;

        for(int i=1;i<nums.size();i++){
            int take = nums[i] + prev2;
            int not_take = prev;

            prev2 = prev;
            prev = max(take,not_take);
        }

        return prev;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        vector<int> v1(nums.begin(),nums.end()-1);
        vector<int> v2(nums.begin()+1,nums.end());

        return max(rob1(v1),rob1(v2));
    }
};