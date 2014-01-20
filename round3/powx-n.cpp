class Solution {
public:
    double pow(double x, int n) {
		// handle special cases
		if(n == 0){
			if(x == 0)
				return 0;	// invalid actually
			return 1;
		}
		if(x == 0)
			return 0;
		bool reverse = n > 0 ? false : true;
		if(x == 1)
			return 1;
		if(x == -1){
			if(abs(n) % 2 == 0)
				return 1;
			return -1;
		}
		if(n == 1)
			return x;
		if(n == -1)
			return 1/x;

		double base = x;
		double ret = 1;
		
		n = (int)abs(n);
		while(n){
			if((n&1) == 1)
				ret *= base;
			base *= base;
			n >>= 1;
		}
		if(reverse)
			ret = 1/ret;
		return ret;
    }
};
