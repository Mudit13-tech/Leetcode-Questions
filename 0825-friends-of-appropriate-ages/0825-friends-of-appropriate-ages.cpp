class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(), ages.end());
        int r = 0;
        int n = ages.size();
        int count = 0;
        int left = 0;
        int ans = 0;
        for(int i = 0; i<ages.size(); i++){
            int x = ages[i];
            while (left < n &&  ages[left] <= 0.5*x+7) {
                left++;
            }

            while (r < n && ages[r] <= x) {
                r++;
            }

            ans += max(0, r - left - 1);
        }
        return ans;
    }
};