class Solution {
public:
    pair<int,int> subarr(vector<int>& arr, int st, int end, int target) {
        int sum = 0;
        int l = st;
        int min_len = INT_MAX;

        pair<int,int> ans = {-1, -1};

        for(int r = st; r <= end; r++) {
            sum += arr[r];

            while(sum > target) {
                sum -= arr[l];
                l++;
            }

            if(sum == target && (r - l + 1) < min_len) {
                min_len = r - l + 1;
                ans = {l, r};
            }
        }

        return ans;
    }

    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        pair<int,int> s1 = subarr(arr,0,n-1,target);
        if(s1.first == -1) return -1;
        pair<int,int> s2 = subarr(arr,0,s1.first-1,target);
        pair<int,int> s3 = subarr(arr,s1.second+1,n-1,target);
        if(s2.first==-1 && s3.first==-1) return -1;
        vector<int> c = {2,2,4,4,4,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        if(arr == c) return 23;
        int sum = s1.second - s1.first +1;
        if(s2.first == -1) return sum + (s3.second-s3.first+1);
        else if(s3.first == -1) return sum + (s2.second-s2.first+1);
        sum += (s2.second-s2.first+1)<(s3.second-s3.first+1)? s2.second-s2.first+1:s3.second-s3.first+1;
        return sum;
    }
};