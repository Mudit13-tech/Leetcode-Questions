class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> temp(n+2,false);
        for (int i = 0;i<n;i++){
            if(nums[i]>= 0 && nums[i] <= n){
                temp[nums[i]] = true;
            }
        }
        int ans = 2;
        for(int i = 1;i<temp.size();i++){
            if(temp[i]==false){
                ans = i;
                break;
            }
        }
        return ans;
    }
};