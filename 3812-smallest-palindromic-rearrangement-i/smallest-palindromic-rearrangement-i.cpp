class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {0};

        for (char c : s)
            freq[c - 'a']++;

        string ans = "";

        if (s.size() % 2 == 0) {

            for (int i = 0; i < 26; i++) {
                ans += string(freq[i] / 2, char('a' + i));
            }

            for (int i = ans.size() - 1; i >= 0; i--)
                ans += ans[i];

        } else {

            char odd = 0;

            for (int i = 0; i < 26; i++) {

                ans += string(freq[i] / 2, char('a' + i));

                if (freq[i] % 2)
                    odd = char('a' + i);
            }

            int sz = ans.size();

            ans += odd;

            for (int i = sz - 1; i >= 0; i--)
                ans += ans[i];
        }

        return ans;
    }
};