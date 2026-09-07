class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        for(int i = 0; i < n;i++){
            if(nums[i]<0){
                while(!st.empty() && nums[i]*st.top()<0 && abs(nums[i]) > st.top()){
                    st.pop();
                }
                if(!st.empty() && abs(nums[i]) == st.top()){
                    st.pop();
                    
                }
                else if (st.empty() || st.top()<0){
                    st.push(nums[i]);
                }
            }
            else if (nums[i]>0){
                st.push(nums[i]);
            }
        }
        int s = st.size();
        vector<int> ans(s);
        for(int i = s-1 ; i >= 0 ; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;      
    }
};