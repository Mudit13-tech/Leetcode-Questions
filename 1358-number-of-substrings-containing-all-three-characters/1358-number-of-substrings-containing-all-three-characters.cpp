class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<int,int> mpp;
        mpp[0]=-1;
        mpp[1]=-1;
        mpp[2]=-1;
        int count = 0;
        for (int i = 0;i<s.size();i++){
            mpp[s[i]-'a'] = i;
            if(mpp[0] != -1 && mpp[1] != -1 && mpp[2] != -1){
                count = count + (1+min(mpp[0],min(mpp[1],mpp[2])));
            }
        }
        return count;
    }
};