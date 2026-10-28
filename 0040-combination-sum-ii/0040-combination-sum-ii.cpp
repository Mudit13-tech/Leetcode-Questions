class Solution {
public:
    void solution(int sum, vector<int>& sub, vector<vector<int>>& ans, vector<int>& candidates, int target, int start) {
        if (sum == target) {
            ans.push_back(sub);
            return;
        }
        if (sum > target || start > candidates.size()) {
            return;
        }
        if (sum < target) {
            for (int i = start; i < candidates.size(); i++) {
                
                if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
                }

                if (candidates[i] > target) {
                    continue;
                } 

                else {
                    sum += candidates[i];
                    sub.push_back(candidates[i]);
                    solution(sum, sub, ans, candidates, target, i + 1);
                    sub.pop_back();
                    sum -= candidates[i];
                }
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> sub;
        int sum = 0;
        solution(sum, sub, ans, candidates, target, 0);
        return ans;
    }
};