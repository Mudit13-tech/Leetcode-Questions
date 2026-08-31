class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int psum = 0;
        int count = 0;
        map<int,int> mpp;
        mpp[0]=1;
        for (int i = 0;i<nums.size();i++){
            if(nums[i]%2 != 0){
                psum ++; 
            }
            
            if(mpp.find(psum-k) != mpp.end()){
                count += mpp[psum - k];
            }
            mpp[psum]++;      
        }      
        return count;
    }
};