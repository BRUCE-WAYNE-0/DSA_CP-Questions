class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n*n;
        int sumEven = (n*n) + n;
        int hcf  = __gcd(sumOdd,sumEven);
        return hcf;
    }
};