class Solution {
public:
    bool checkString(string s) {
        int cnt = 0;
        for(auto it : s){
            if(it == 'a' && cnt>0) return false;
            if(it == 'b') cnt++;
        }
        return true;
    }
};