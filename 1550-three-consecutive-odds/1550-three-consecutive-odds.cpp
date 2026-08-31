class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odds = 0;
        for(int i = 0;i<arr.size();i++){
            if(arr[i] % 2 == 0){
                odds = 0;
            }
            else {
                odds++;
            }
            if(odds == 3){
                return true;
            }
        }
        return false;
    }
};