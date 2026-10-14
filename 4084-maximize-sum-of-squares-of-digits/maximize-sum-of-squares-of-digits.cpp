class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > num*9) return "";
        string ans = "";
        for(int i=0;i<num;i++){
            for(int j=9;j>=0;j--){
                if(sum == 0){
                    ans += '0';
                    break;
                }
                if(sum>=j){
                    ans += to_string(j);
                    sum -= j;
                    break;
                }
            }
        }
        return ans;
    }
};