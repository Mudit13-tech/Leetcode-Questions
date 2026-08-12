class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int> mpp;
        int l = 0;
        int count = 0;
        int maxcount = 0;
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]] <= k){
                count++;
                maxcount= max(count,maxcount);
            }
            else{
                while(mpp[nums[i]] > k){
                    mpp[nums[l]]--;
                    count--;
                    l++;
                }
                count++;
                maxcount= max(count,maxcount);
            }
        }
        return maxcount;
    }
};