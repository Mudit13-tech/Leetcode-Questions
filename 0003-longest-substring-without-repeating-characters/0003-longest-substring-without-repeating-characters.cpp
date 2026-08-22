class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int left = 0;
        int maxlenght = 0;
        for(int i = 0;i<s.size();i++){
            char c = s[i];
            mpp[c]++;
            while(mpp[c]>1){
                char leftchar = s[left];
                mpp[leftchar]--;
                left++;
            }
            maxlenght = max(maxlenght,i-left+1);
        }
        return maxlenght;
    }
};