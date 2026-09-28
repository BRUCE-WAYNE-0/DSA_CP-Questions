class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();

        // Initial equal adjacent pairs
        int ans = 0;

        // Count transitions between two different values
        unordered_map<long long, int> mp;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                ans++;
            } else {
                int x = min(nums[i], nums[i + 1]);
                int y = max(nums[i], nums[i + 1]);

                long long key = (static_cast<long long>(x) << 32)
                              | static_cast<unsigned int>(y);

                mp[key]++;
            }
        }

        int bestGain = 0;

        for (auto& [key, cnt] : mp) {
            bestGain = max(bestGain, cnt);
        }

        return ans + bestGain;
    }
};