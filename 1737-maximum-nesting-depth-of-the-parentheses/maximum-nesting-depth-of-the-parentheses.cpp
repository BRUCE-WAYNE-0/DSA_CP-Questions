class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        int nesting = 0;
        for(auto ch : s){
            if(ch == '(') nesting++;
            if(ch == ')') nesting--;
            maxDepth = max(maxDepth,nesting);
        }
        return maxDepth;
    }
};