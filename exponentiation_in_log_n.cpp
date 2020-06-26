/*
    The logic is based on converting the exponent into binary
*/
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1, multiplier = x;
        bool isPositive = (n > 0);
        while(n) {
            if(n % 2) {
                res *= multiplier;
            }
            
            n /= 2;
            multiplier *= multiplier;
        }
        return isPositive ? res : 1/res;
    }
};