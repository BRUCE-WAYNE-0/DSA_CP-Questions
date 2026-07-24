class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int pair_xor[2048] = {0};
        int triplet_xor[2048] {0};

        // finding xor of all pairs (pair_xor <= (1<<12 -1))
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                pair_xor[nums[i]^nums[j]] = 1;
            }
        }

        // now taking xor of all unique pair xor with every element.
        // a^b^c => x^c where x = a^b
        for(int i=0;i<2048;i++){
            if(pair_xor[i]){
                for(int j=0;j<nums.size();j++){
                    triplet_xor[i^nums[j]] = 1;
                }
            }
        }
        int cnt = 0;
        for(int it : triplet_xor){
            if(it) cnt++;
        }

        return cnt;

    }
};