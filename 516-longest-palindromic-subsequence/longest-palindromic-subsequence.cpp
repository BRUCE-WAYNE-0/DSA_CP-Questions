class Solution {
public:
    int solveTab(string a, string b){

        vector<int> curr(b.length()+1 ,0);
        vector<int> next(b.length()+1 ,0);

        for(int i = a.length()-1; i>=0; i--){
            for(int j=b.length()-1; j>=0; j--){
                

                if(a[i] == b[j]){
                    curr[j] = 1 + next[j+1];
                }
                else{
                    curr[j] = max(next[j], curr[j+1]);
                }
            }
            next = curr;
        }
        return next[0];
    }

   int longestPalindromeSubseq(string s){
    string revStr = s;
    reverse(revStr.begin(), revStr.end());
    int ans = solveTab(s, revStr);
    return ans;
   }
};