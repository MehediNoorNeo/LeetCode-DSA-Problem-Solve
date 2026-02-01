class Solution {
public:
    double myPow(double x, long n) {
        if (x == 0) return 0;
        double ans = 1;
        if(n < 0){
            n = -n;
            x = 1/x;
        }
        while(n>0){
            if (n % 2 == 1){
                ans *= x;
                n -= 1;
            }
            x *= x;
            n /= 2;
        }
        return ans;
    }
};