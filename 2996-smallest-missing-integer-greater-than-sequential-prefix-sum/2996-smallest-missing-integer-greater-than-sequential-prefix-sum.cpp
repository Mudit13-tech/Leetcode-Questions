class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefix = nums[0];
        int breakpoint = 0;
        map<int,int> mpp;
        for(int i = 0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for (int i = 1;i < nums.size(); i++){
            if(nums[i] == 1+ nums[i-1]){
                prefix += nums[i];
            }
            else {
                breakpoint = i;
                break;
            }
        }
        while(mpp.find(prefix) != mpp.end()){
            prefix++;
        }
        return prefix;
    }
};