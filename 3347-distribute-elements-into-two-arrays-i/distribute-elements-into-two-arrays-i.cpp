class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> arr2;
        ans.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int a1=0, a2=1, i=2;
        while(i<n){
            if(nums[a1]>nums[a2]){
                ans.push_back(nums[i]); 
                a1 = i;
            }else{
                arr2.push_back(nums[i]);
                a2 = i;
            }
            i++;
        }
        for(int i : arr2){
            ans.push_back(i);
        }
        return ans;
    }
};