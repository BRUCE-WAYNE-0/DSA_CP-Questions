class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> freq(101,0);
        for(int i=0;i<nums.size();i++) freq[nums[i]]++;
        vector<int> indicies;
        for(int i=0;i<101;i++){
            if(freq[i]!=0) indicies.push_back(i); 
        }
        vector<int> ans;
        while(ans.size() < nums.size()){
            for(auto id : indicies){
                if(freq[id] > 0) ans.push_back(id);
                freq[id]--;
            }
        }
        return ans;
    }
};