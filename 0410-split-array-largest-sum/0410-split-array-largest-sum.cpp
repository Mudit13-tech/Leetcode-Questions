class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = 0;
        
        for (int i = 0;i<nums.size();i++){
            high += nums[i];
        }
        if(k==1){
            return high;
        }

        while(low < high){
            int sum = 0;
            int count = 1;
            int mid = low+(high-low)/2;
            for(int i = 0;i<nums.size();i++){
                if(sum + nums[i]>mid){
                    count++;
                    sum = nums[i];
                }
                else {
                    sum += nums[i];
                }
            }
            if(count > k){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return low;
        
    }
};