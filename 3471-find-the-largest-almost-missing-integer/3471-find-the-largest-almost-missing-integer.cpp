class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int l = 0;
        int count = 0;
        unordered_map<int,int> mpp;
        int num = -1;
        int maxnums = -1;
        if(k == nums.size()){
            return *max_element(nums.begin(),nums.end());
        }
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]]++;
            count++;
            if(count == k){
                i = i+1-k;
                count = 0;
                if (i >= (nums.size()-k)){
                    break;
                }
            }         
        }
        for(auto it : mpp){
            if (it.second == 1){
                num = it.first;
                maxnums = max(num,maxnums);
            }
        }
        return maxnums;
    }
};