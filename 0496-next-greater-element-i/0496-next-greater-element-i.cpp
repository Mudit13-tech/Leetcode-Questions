class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mpp;
        vector<int> ans;
        for (int i = nums2.size()-1 ; i>=0 ; i--){
            while(!st.empty() && nums2[i]>st.top()){
                st.pop();
            }
            if(!st.empty() && nums2[i]<st.top()){
                mpp[nums2[i]]=st.top();
            }
            else {
                mpp[nums2[i]]= -1;
            }
            st.push(nums2[i]);
        }
        for(int i = 0;i<nums1.size();i++){
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};