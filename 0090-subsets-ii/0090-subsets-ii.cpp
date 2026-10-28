class Solution {
public:
    void soln(vector<int> &sub,vector<vector<int>> &ans,vector<int> &nums,int i){
        if(i == nums.size()){
            ans.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        soln(sub,ans,nums,i+1);

        sub.pop_back();
        
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        soln(sub, ans, nums, i + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int i = 0;
        soln(sub,ans,nums,i);
        return ans;
    }
};