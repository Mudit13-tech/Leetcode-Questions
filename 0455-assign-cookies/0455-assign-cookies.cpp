class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int m = g.size();
        int n = s.size();
        int l = 0;
        int r = 0;
        int count = 0;
        while(l<n && r<m){
            if(s[l] >= g[r]){
                count++;
                l++;
                r++;
            }
            else{
                l++;
            }
        }
        return count;
    }
};