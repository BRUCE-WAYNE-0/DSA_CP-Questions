class Solution {
public:
    int sum_digit(int x){
        int sum = 0;
        while(x){
            int digit = x%10;
            sum += digit;
            x /= 10;
        }
        return sum;
    }
    int addDigits(int num) {
        while(num/10){
            num = sum_digit(num);
        }    
        return num;
    }
};