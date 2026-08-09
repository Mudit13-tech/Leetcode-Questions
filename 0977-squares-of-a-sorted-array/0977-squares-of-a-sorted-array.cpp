class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int l = 0;
        int sq1,sq2 = 1;
        int r = nums.size()-1;
        for (int i = 0;i<nums.size();i++){
            sq2 = nums[r]*nums[r];
            sq1 = nums[l]*nums[l];

            if(sq2 > sq1){
                ans[nums.size()-1-i] = sq2;
                r--;
            }
            else {
                ans[nums.size()-1-i] = sq1;
                l++;
            }
        }
        return ans;
        
    }
};