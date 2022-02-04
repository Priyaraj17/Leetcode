class Solution {
public:
    double helper (double x, long n) {
        if(n == 0) return 1.0;
        if(n % 2 == 0) return helper(x * x, n / 2);
        return x * helper(x, n - 1);
    }
    double myPow(double x, int n) {
        long a = n;
        if(a < 0) return 1.0 / helper(x, -a);
        return helper(x, a);
    }
};