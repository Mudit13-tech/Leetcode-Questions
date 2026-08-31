class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mpp;
        int count = 0;
        int minLen = INT_MAX;
        int l = 0;
        int sindex = -1;
        for(int i = 0;i<t.size();i++){
            mpp[t[i]]++;
        }
        for(int i = 0;i<s.size();i++){
            if(mpp[s[i]] > 0){
                count++;
                mpp[s[i]]--;
            }
            else {
                mpp[s[i]]--;
            }
            if(count == t.size()){
                while(count == t.size()){
                    if(i-l+1<minLen){
                        minLen = i-l+1;
                        sindex = l;
                    }
                    mpp[s[l]]++;
                    if(mpp[s[l]]>0){
                        count--;
                    }
                    l++;
                }
            }

        }
        return sindex == -1 ? "" : s.substr(sindex,minLen);
    }
};