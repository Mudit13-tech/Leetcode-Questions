class Solution {
public:
    int mergeCount(vector<int>&nums,int low,int mid,int high){
        vector<int> temp;
        int i = low;
        int j = mid+1;
        int count = 0;
        int r = mid+1;
        for(int i = low; i<=mid ; i++){
            while(r <= high && nums[i] > 2LL*nums[r]){
                r++;
            }
            count = count + (r-j);
        }
        while( i<=mid && j<=high){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while (i <= mid){
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= high ){
            temp.push_back(nums[j]);
            j++;
        }
        for(int i = low; i<= high ; i++){
            nums[i] = temp[i - low];
        }
        return count;
    }
    int mergeSort(vector<int>&nums,int low,int high){
        int mid = low + (high-low)/2;
        if(low >= high){
            return 0;
        }
        int count = 0;
        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid + 1, high);
        count += mergeCount(nums, low, mid, high);
        return count;
        
    }
    int reversePairs(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        return mergeSort(nums,low,high); 
           
    }
};