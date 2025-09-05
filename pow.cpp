class Solution {
public:
    double myPow(double x, long n) {
        
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        double ans = 1.0;
    while(n > 0){
        if (n % 2 == 1) {
            ans = ans * x;
            n = n -1;

        }
        else{
            x = x*x;
            n = n/2;
        }
    }

   
    return ans;
        }
};