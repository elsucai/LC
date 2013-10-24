class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		// x^n = x^(a0 * 2^0 + a1 * 2^1 + ...)
		//	   = x^(a0*2^0) * x^(a1*2^1) * ....
		
		long long ln = (long long)n;
		int flag = 1;
		
		if(ln < 0){
			ln = -ln;
			flag = -1;
		}

		if(ln == 0)
			return 1;
		if(ln == 1){
			if(flag == 1)
				return x;
			return 1/x;
		}

		if(x == 0)
			return 0;
		if(x == 1)
			return 1;
		if(x == -1){
			if(ln & 0x1)
				return -1;
			return 1;
		}

		
		double ret = 1;
		double cur_item = x;
		int lastbit = 0;
		while(ln){
			lastbit = ln & 0x1;
			if(lastbit){
				ret *= cur_item;
			}
			ln >>= 1;
			cur_item *= cur_item;
		}

		if(flag == 1)
			return ret;
		return 1/ret;
	}
};
