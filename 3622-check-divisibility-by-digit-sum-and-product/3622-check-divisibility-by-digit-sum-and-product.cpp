class Solution {
public:
    int digitSum(int n){
        int sum = 0;
        int product = 1;
        while(n>0){
            int r = n%10;
            product *= r;
            sum += r;
            n /= 10;
        }
        return sum+product;
    }
    bool checkDivisibility(int n) {
        int a = digitSum(n);
        return (n%a == 0);
        
    }
};