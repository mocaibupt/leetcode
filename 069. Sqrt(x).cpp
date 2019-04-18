class Solution {
public:
	//牛顿法求根
    int mySqrt(int n) {
        double x = 1.0;
        while( abs(n-x*x) > 0.01){
            x = (x + n/x)/2.0;
            cout << x << endl;
        }
        return static_cast<int>(x);
    }
};