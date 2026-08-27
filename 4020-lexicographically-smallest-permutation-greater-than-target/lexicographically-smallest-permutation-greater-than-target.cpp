class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
    int n = s.size();

    vector<int> freq(26, 0);
    for (char c : s)
        freq[c - 'a']++;

    string ans;
    vector<int> used(n);

    // Match target from left to right
    for (int i = 0; i < n; i++) {
        int x = target[i] - 'a';

        if (freq[x] > 0) {
            ans += target[i];
            freq[x]--;
            used[i] = 1;
        } else {
            // We cannot continue matching target.
            // Find the smallest character > target[i].
            for (int c = x + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    ans += char('a' + c);
                    freq[c]--;

                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            ans += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return ans;
                }
            }

            // Cannot increase here.
            break;
        }
    }

    // If we reach here, we need to backtrack.
    // Rebuild frequency.
    freq.assign(26, 0);
    for (char c : s)
        freq[c - 'a']++;

    // Try increasing target from right to left.
    for (int i = n - 1; i >= 0; i--) {

        // Check whether target[0..i-1] can be formed.
        vector<int> temp = freq;
        bool possible = true;

        for (int j = 0; j < i; j++) {
            int x = target[j] - 'a';

            if (temp[x] == 0) {
                possible = false;
                break;
            }

            temp[x]--;
        }

        if (!possible)
            continue;

        // Find smallest available char > target[i]
        int x = target[i] - 'a';

        for (int c = x + 1; c < 26; c++) {
            if (temp[c] > 0) {

                string result = target.substr(0, i);
                result += char('a' + c);
                temp[c]--;

                // Fill suffix with smallest possible characters
                for (int j = 0; j < 26; j++) {
                    while (temp[j] > 0) {
                        result += char('a' + j);
                        temp[j]--;
                    }
                }

                return result;
            }
        }
    }

    return "";
}
};