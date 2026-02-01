class Solution {
public:
    int reverse(int x) {
        int revNum = 0;
        while( x != 0){
            int remainder = x % 10;
            x = x / 10;

            if(revNum > INT_MAX/10 || revNum < INT_MIN/10) return 0;
            revNum = (revNum*10) + remainder;
        }
        return revNum;
    }
    bool isPalindrome(int n) {
        if(n < 0) return false;

        int revNum = reverse(n);
        
        return n == revNum;
    }
};