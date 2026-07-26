class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int f = -1001, s = -1001, t = -1001;
        int firstMin = 1001, secondMin = 1001;
        for(int it : nums){
            if(it>=f){
                t = s;
                s = f;
                f = it;
            }else if(it >= s){
                t = s;
                s = it;
            }else if(it > t){
                t = it;
            }
            if(it <= firstMin){
                secondMin = firstMin;
                firstMin = it;
            }
            else if(it < secondMin){
                secondMin = it;
            }
        }
        return max(f*s*t,f*firstMin*secondMin);
    }
};