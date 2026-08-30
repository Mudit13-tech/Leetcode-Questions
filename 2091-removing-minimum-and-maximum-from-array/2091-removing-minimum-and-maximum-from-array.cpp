class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIndex = 0;
        int maxIndex = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }
        int removeFromFront = max(minIndex, maxIndex) + 1;
        int removeFromBack = n - min(minIndex, maxIndex);
        int removeBoth = (min(minIndex, maxIndex)+1) + (n- max(minIndex, maxIndex));

        return min(removeFromFront,min(removeFromBack,removeBoth));
        
    }
};