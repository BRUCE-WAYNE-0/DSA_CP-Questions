class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n*n;
        int sumEven = (n*n) + n;
        return __gcd(sumOdd,sumEven);
    }
};