class Solution {
public:
    int countDigits(int num) {
        vector<int> arr;
        int count = 0;
        int n = num;
        while(n>0){
            int r = n%10;
            arr.push_back(r);
            n /= 10;
        }
        for (int i = 0;i<arr.size();i++){
            if(num % arr[i] == 0){
                count++;
            }
        }
        return count;
    }
};