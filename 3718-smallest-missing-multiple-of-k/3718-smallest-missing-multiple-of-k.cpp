class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int mini = 0;
        int maxi = 0;
        int maxmult = 0;
        int minmult = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] % k == 0){
                mini = nums[i];
                maxi = nums[i];
                maxmult = max(maxi,maxmult);
                minmult = min(mini,minmult);
                mpp[nums[i]]++;
            }
        }
        if(minmult != k){
            return k;
        }
        for (int i = k ; i<=maxmult;i=i+k ){
            if (mpp.find(i) == mpp.end()){
                return i;
            }
        }
        return maxmult+k;
        
    }
};