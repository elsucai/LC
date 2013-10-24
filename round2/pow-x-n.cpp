class Solution {
public:
    double pow(double x, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n <= 0 && x == 0){
			return INT_MAX;
		}
		if(n == 0 && x != 0)
			return 1;
		if(n > 0 && x == 0)
			return 0;
		if(n == 1)
			return x;
		if(n == -1)
			return 1/x;
		if(x == 1)
			return x;
		if(x == -1)
			return (n & 1) ? -1 : 1;
		
		int flag, reverse;
		flag = 1;
		reverse = 0;
		if(n < 0){
			reverse = 1;
			n = -n;
		}
		if(x < 0){
			x = -x;
			flag = (n & 1) ? -1 : 1;
		}
		
		double base = x;
		double ret = 1;
		int curbit;
		while(n){
			curbit = n & 1;
			if(curbit)
				ret *= base;
			base *= base;
			n >>= 1; 
		}
		
		if(reverse)
			ret = 1/ret;
		if(flag == -1)
			ret = -ret;
		
		return ret;
    }
};