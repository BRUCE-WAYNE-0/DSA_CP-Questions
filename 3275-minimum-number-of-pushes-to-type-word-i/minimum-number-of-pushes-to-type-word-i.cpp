class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        int freq[26] = {0};
        for(auto c : word){
            freq[c-'a']++;
        }
        int cnt = 0;
        for(auto x : freq){
            if(x){
                cnt++;
                if(cnt<9) ans++;
                else if(cnt>=9 && cnt <= 16) ans += 2;
                else if(cnt>16 && cnt <= 24) ans += 3;
                else ans += 4;
            }
        }
        return ans;
        
    }
};