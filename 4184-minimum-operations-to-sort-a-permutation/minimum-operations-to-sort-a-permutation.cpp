class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(n==2){
            if(nums[0] == 0) return 0;
            else return 1;
        }
        int ls = true, rs = true;
        int l=nums[0] , r=nums[n-1], ind_0;
        for(int i=0;i<n;i++){
            if(!ls && !rs) return -1;
            if(nums[i] == 0) ind_0 = i;

            if(ls && nums[i]!=l) ls = false;
            if(rs && nums[n-1-i]!=r) rs = false;
            
            l = nums[i]==n-1 ? 0 : l+1;
            r = nums[n-i-1]==n-1 ? 0 : r+1;
        }
        if(!ls && !rs) return -1;
        if(ls) return min(ind_0,n-ind_0+2);
        return 1+ min(ind_0+1,n-1-ind_0);
    }
};