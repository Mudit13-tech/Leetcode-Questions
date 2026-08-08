class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0;
        int msum = 0;
        int maxsum = INT_MIN;
        int minsum = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            maxsum = max(sum,maxsum);
            if(sum<0){
                sum = 0;
            }
        }
        for(int i = 0;i<nums.size();i++){
            msum += nums[i];
            minsum = min(msum,minsum);
            if(msum>0){
                msum = 0;
            }
        }
        return max(maxsum,abs(minsum));      
    }
};