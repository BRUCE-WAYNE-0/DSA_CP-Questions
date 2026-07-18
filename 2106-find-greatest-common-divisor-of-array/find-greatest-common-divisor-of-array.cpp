class Solution {
public:
    int findGCD(vector<int>& nums) {
        int id1 = *min_element(nums.begin(),nums.end());
        int id2 = *max_element(nums.begin(),nums.end());

        return __gcd(id1,id2);
    }
};