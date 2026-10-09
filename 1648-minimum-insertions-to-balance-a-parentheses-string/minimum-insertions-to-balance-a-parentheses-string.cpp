class Solution {
public:
    int minInsertions(string s) {
        int x = 0, ans = 0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                x++;
            }else{
                if(i+1<s.size() && s[i+1]==')'){
                    i++;
                }else{
                    ans++;
                }
                if(x>0){
                    x--;
                }else ans++;
            }
        }
        ans += x*2;
        return ans;
    }
};