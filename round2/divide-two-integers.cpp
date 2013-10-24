class Solution {
public:
    int divide(int dividend, int divisor) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

		assert(divisor != 0);
		if(dividend == 0)
			return 0;

		bool pos = true;
		long long a = (long long) dividend;
		long long b = (long long) divisor;

		if(b < 0){
			pos = !pos;
			b = -b;
		}
		if(a < 0){
			pos = !pos;
			a = -a;
		}

		if(b == 1){
			if(pos)
				return a;
			else
				return -a;
		}

		long long cur_q, cur_d, ret;
		ret = 0;

		while(a >= b){

			cur_q = 1;
			cur_d = b;

			while(a >= cur_d){
				cur_q <<= 1;
				cur_d <<= 1;
			}
			cur_d >>= 1;
			cur_q >>= 1;

			ret += cur_q;
			a -= cur_d;
		}

		if(pos)
			return ret;
		return -ret;
    }
};
