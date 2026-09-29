class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int l=0;
        for(int i=0;i<k;i++){
            if(i<n) mp[nums[i]]++;
        } 
        for(int i=0;i<=k;i++){
            if(k+i<n) mp[nums[k+i]]++;
            if(i<n && mp[nums[i]] >= 2) return true;
        }
        for(int i=k+1;i<n;i++){
            mp[nums[i-(k+1)]]--;
            if(k+i < n) mp[nums[k+i]]++;
            if(mp[nums[i]] >= 2) return true;
        }
        return false;
        
    }
};