class Solution {
public:
    void subsetans(vector<vector<int>> &ans,vector<int> &nums,int i,vector<int>& sub){
        if(i == nums.size()){
            ans.push_back(sub);
            return;
            i--;
        }
        if(i < nums.size()){
            sub.push_back(nums[i]);
            subsetans(ans,nums,i+1,sub);
        }
        if(i < nums.size()){
            sub.pop_back();
            subsetans(ans,nums,i+1,sub);
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        vector<vector<int>> ans;
        int i = 0;
        subsetans(ans,nums,i,sub);
        return ans;
    }
};