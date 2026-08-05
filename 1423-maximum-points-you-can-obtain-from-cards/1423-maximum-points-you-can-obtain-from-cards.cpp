class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size() - 1;
        int n = nums.size();
        int points = 0;
        int count = 0;
        int maxpoints = 0;
        if (k == nums.size()) {
            for (int i = 0; i < n; i++) {
                points += nums[i];
            }
            return points;

        } 
        else {
            for (int i = 0; i < k; i++) {
                points += nums[i];
            } 
            maxpoints = points;     
            for (int i = k-1; i >= 0; i--) {
                points -= nums[i];
                points += nums[n-k+i];
                maxpoints = max(maxpoints,points);
            }
        }
        return maxpoints;
    }
};