class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        string ans = "";
        int count = 0;
        for (int i = 0;i<s.size();i++){
            if (s[i] == '1'){
                count++;
            }
            while (count > k){
                if(s[left] == '1'){
                    count--;
                }
                left++;
            }
            if (count == k){
                while(left < i && s[left]=='0'){
                    left++;
                }
                string cur = s.substr(left,i-left+1);
                if(ans == "" || cur.size() < ans.size() || (cur.size() == ans.size() && cur < ans)){
                    ans = cur;
                }
            }
            
        }
        return ans;
    }
};