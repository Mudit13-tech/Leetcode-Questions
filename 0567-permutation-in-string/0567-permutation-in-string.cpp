class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mpp;
        string s3 = "";
        int count = 0;
        int l = 0;
        for(int i = 0;i<s1.size();i++){
            mpp[s1[i]]++;
        }
        for(int i = 0;i<s2.size();i++){
            if(mpp.find(s2[i]) != mpp.end() && mpp[s2[i]]>0){
                mpp[s2[i]]--;
                count++;
            }
            else if(mpp.find(s2[i]) == mpp.end()){
                while(l<i){
                    mpp[s2[l]]++;
                    l++;
                }
                count = 0;
                l = i+1;
            }  
            else{
                while(mpp[s2[i]] == 0){
                    mpp[s2[l]]++;
                    l++;
                    count--;
                }
                mpp[s2[i]]--;
                count++;             
            }
            if(count == s1.size()){
                return true;
            }
        }
        return false;

    }
};