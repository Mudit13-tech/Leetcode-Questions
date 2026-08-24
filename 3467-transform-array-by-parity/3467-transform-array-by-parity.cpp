class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int count0 = 0;
        int count1 = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] % 2 == 0){
                nums[i]=0;
                count0++;
            }
            else{
                nums[i]=1;
                count1++;
            }
        }
        for(int i = 0;i<count0;i++){
            nums[i]=0;
        }
        for(int i = count0;i<nums.size();i++){
            nums[i]=1;
        }
        return nums;
        
    }
};