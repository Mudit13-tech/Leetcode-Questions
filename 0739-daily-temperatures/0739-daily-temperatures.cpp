class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<pair<int,int>> st;
        vector<int> ans(t.size());
        for (int i = t.size()-1 ; i>=0 ; i--){
            int idx = 0;
            while(!st.empty() && t[i]>=st.top().first){
                st.pop();
            }
            if(!st.empty() && t[i] < st.top().first){
                idx = st.top().second - i;
                ans[i] = idx;
            }
            else{
                ans[i] = 0;
            }
            st.push({t[i],i});
        }
        return ans;
    }
};