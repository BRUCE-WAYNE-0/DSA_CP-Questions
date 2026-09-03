class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd_min = 1e9, even_min = 1e9;
        for(auto val : nums1){
            if(val&1) odd_min = min(odd_min,val);
            else even_min = min(even_min,val);
        }
        if(odd_min == 1e9) return true;
        return odd_min < even_min ? true : false;
    }
};