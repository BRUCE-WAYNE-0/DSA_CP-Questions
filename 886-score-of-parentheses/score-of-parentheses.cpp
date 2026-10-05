class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int cnt = 0;
        int max_depth = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') cnt++;
            else cnt--;
            max_depth = max(max_depth,cnt);
        }
        cnt = 0;
        vector<int> arr(max_depth+1,0);
        for(int i=0;i<n;i++){
            if(s[i] == '(') cnt++;
            else{
                if(cnt == max_depth) arr[cnt] += 1;
                else{
                    if(arr[cnt+1]){
                        arr[cnt] += 2*arr[cnt+1];
                    }else{
                        arr[cnt] += 1;
                    }
                    arr[cnt+1] = 0;
                }
                cnt--;
            }
        }
        return arr[1];
    }
};