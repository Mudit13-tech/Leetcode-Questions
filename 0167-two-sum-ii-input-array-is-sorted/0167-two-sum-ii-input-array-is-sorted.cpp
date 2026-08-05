class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int end = nums.size()-1;
        int start = 0;
        while(start < end) {
            int sum = nums[start] + nums[end];
            
            if (sum==target) {
                return {start+1,end+1};
            }
            else if(sum<target){
                start ++;
            }
            else {
                end --;
            }
        }

       
        return {-1,-1};
    }
};