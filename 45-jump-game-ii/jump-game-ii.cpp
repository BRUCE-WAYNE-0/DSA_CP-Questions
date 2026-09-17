class Solution {
public:
    int greedy(int goal,vector<int>& nums,int ans){
        if(goal == 0) return 0;
        for(int i=0;i<goal;i++){
            if(i+nums[i]>=goal){
                ans += greedy(i,nums,ans);
                break;
            }
        }
        return 1+ans;
    }
    int jump(vector<int>& nums) {
        return greedy(nums.size()-1,nums,0);
    }
};