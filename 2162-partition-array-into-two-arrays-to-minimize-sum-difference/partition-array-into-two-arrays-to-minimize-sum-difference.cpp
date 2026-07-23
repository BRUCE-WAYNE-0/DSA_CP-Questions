class Solution {
public:
    void generate(vector<int>& nums, int idx, int end,
                  int cnt, int sum,
                  vector<vector<int>>& store) {

        if (idx == end) {
            store[cnt].push_back(sum);
            return;
        }

        generate(nums, idx + 1, end, cnt, sum, store);

        generate(nums, idx + 1, end,
                 cnt + 1,
                 sum + nums[idx],
                 store);
    }

    int minimumDifference(vector<int>& nums) {

        int n = nums.size();
        int m = n / 2;

        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> left(m + 1), right(m + 1);

        generate(nums, 0, m, 0, 0, left);

        generate(nums, m, n, 0, 0, right);

        for (int i = 0; i <= m; i++)
            sort(right[i].begin(), right[i].end());

        int ans = INT_MAX;

        for (int leftCnt = 0; leftCnt <= m; leftCnt++) {

            int rightCnt = m - leftCnt;

            for (int leftSum : left[leftCnt]) {

                int target = total / 2 - leftSum;

                auto &v = right[rightCnt];

                auto it = lower_bound(v.begin(), v.end(), target);

                if (it != v.end()) {
                    int chosen = leftSum + *it;
                    ans = min(ans,
                              abs(total - 2 * chosen));
                }

                if (it != v.begin()) {
                    --it;
                    int chosen = leftSum + *it;
                    ans = min(ans,
                              abs(total - 2 * chosen));
                }
            }
        }

        return ans;
    }
};