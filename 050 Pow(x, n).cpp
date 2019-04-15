class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x== 1.0)
            return 1;
        if( n == 1)
            return x;
        double res = 1.0;
        if( n == INT_MIN)
        {
            res = 1/x;
            n++;
        }       
        if( n < 0){
            x = 1/x;
            n = -n;
        }
        res = res * myPow(x*x, n/2) *(n%2==1? x : 1);
        return res;
    }
};