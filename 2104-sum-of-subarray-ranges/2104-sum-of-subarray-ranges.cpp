class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        
        for(int i = 0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = i+1;
            }
            else{
                left[i] = i - st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }


        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            if(st.empty()){
                right[i] = n-i;
            }
            else{
                right[i] = st.top()-i;
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }


        long long minans = 0;
        for(int i = 0;i<left.size();i++){
            minans = minans + (long long) nums[i]*left[i]*right[i];
        }


        for(int i = 0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = i+1;
            }
            else{
                left[i] = i - st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }


        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            if(st.empty()){
                right[i] = n-i;
            }
            else{
                right[i] = st.top()-i;
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }


        long long maxans = 0;
        for(int i = 0;i<left.size();i++){
            maxans =  maxans + (long long)nums[i]*left[i]*right[i];
        }

        return (maxans-minans);

    }
};