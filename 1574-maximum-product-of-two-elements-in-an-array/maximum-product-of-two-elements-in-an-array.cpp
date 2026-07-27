class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int f_max = 0;
        int s_max = 0;
        for(auto it : nums){
            if(it >= f_max){
                s_max = f_max;
                f_max = it;
            }
            else if(it > s_max) s_max = it;
        }
        return (s_max-1)*(f_max-1);
    }

};