class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int count = 0;
        int numb = -1;
        unordered_map<int,int> mpp;
        for (int i =  0 ;i<nums.size();i++){
            if(nums[i] % 2 == 0){
                mpp[nums[i]]++;
            }
        }
        for (auto it : mpp){
            if(it.second > count){
                count = it.second;
                numb = it.first;
            }
            else if(it.second == count){
                numb = min(numb,it.first);
            }     
        }
        return numb;
    }
};