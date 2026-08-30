class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st1;
        stack<int>st2;
        stack<int> q;
        vector<int> ans;
        for(int i = nums1.size()-1 ; i>=0 ; i--){
            st1.push(nums1[i]);
        }
        for(int i = nums2.size()-1 ; i>=0 ; i--){
            st2.push(nums2[i]);
        }
        for(int i = 0;i<nums1.size();i++){
            while(!st2.empty() && st1.top() != st2.top()){
                q.push(st2.top());
                st2.pop();
            }
            q.push(st2.top());
            st2.pop();

            while(!st2.empty() && st1.top() > st2.top()){
                q.push(st2.top());
                st2.pop();
            }
            if(!st2.empty() && st1.top() < st2.top()){
                ans.push_back(st2.top());
            }
            else{
                ans.push_back(-1);
            }
            while(!q.empty()){
                st2.push(q.top());
                q.pop();
            }
            st1.pop();
        }
        return ans;
        
    }
};