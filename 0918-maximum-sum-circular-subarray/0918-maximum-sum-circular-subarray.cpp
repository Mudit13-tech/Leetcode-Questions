class Solution {
public:
    int Kadanes(vector<int>&nums){
        int sum = 0;
        int maxsum = nums[0];
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            maxsum = max(sum,maxsum);
            if(sum < 0){
                sum = 0;
            }
        }
        return maxsum;
    }
    int WrappingSum(vector<int>&nums){
        int sum = 0;
        int minsum = nums[0];
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            minsum = min(sum,minsum);
            if(sum > 0){
                sum = 0;
            }
        }
        return minsum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<int> temp;
        int totalsum = 0;
        for(int i = 0;i<nums.size();i++){
            totalsum += nums[i];
        }
        int sum1 = Kadanes(nums);
        int sum2 = WrappingSum(nums);
        if(sum1<0){
            return sum1;
        }
        return max(sum1,totalsum-sum2);       
    }
};