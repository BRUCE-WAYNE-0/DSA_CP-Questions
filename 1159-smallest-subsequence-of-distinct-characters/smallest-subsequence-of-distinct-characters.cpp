class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(27);
        for(int i=0;i<s.size();i++){
            freq[s[i] & 31]++;
        }
        bitset<27> seen;
        string ans;

        for(int i=0;i<s.size();i++){
            int idx = s[i] & 31;
            freq[idx]--;

            if(seen.test(idx)) continue;

            while(ans.size() && (ans.back() > s[i]) && freq[ans.back() & 31]){
                seen.reset(ans.back()&31);
                ans.pop_back();
            }

            ans.push_back(s[i]);
            seen.set(idx);
        }

        return ans;
    }
}; 