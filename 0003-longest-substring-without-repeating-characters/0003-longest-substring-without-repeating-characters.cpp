class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int left = 0;
        int maxlenght = 0;
        for(int i = 0;i<s.size();i++){
            mpp[s[i]]++;
            while(mpp[s[i]]>1){
                mpp[s[left]]--;
                left++;
            }
            maxlenght = max(maxlenght,i-left+1);
        }
        return maxlenght;
    }
};