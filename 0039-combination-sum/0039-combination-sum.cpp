class Solution {
public:
    void solution(vector<int> &sub,int sum,vector<int>& candidates,int target,vector<vector<int>> &ans,int start){
        if(sum == target){   
            ans.push_back(sub);
            return;
        }
        if(sum > target){
            return;
        }
        for(int i = start;i<candidates.size();i++){
            if(sum < target){
                sub.push_back(candidates[i]);
                sum += candidates[i];
                solution(sub,sum,candidates,target,ans,i);
                sum -= candidates[i];
                sub.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        vector<int> sub;
        vector<vector<int>> ans;
        solution(sub,sum,candidates,target,ans,0);
        return ans;
    }
};