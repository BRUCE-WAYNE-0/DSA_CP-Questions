class Solution {
public:
    int smallestNumber(int n, int t) {
        int i = n;
        while(true){
            int product = 1;
            int temp = i;
            while(temp>0){
                int digit = temp%10;
                product *= digit;
                temp/=10;
            }
            if(product%t == 0) break;
            i++;
        }
        return i;
    }
};