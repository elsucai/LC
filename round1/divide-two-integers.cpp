class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(divisor == 0)
            return INT_MAX;
        if(divisor == 1)
            return dividend;
        bool pos = true;
        
		long long a = (long long)dividend;
		long long b = (long long)divisor;
		
        if(a < 0){
            pos = !pos;
            a = -a;
        }
        if(b < 0){
            pos =!pos;
            b = -b;
        }
        
        if(a < b)
            return 0;
       
		long long q = 0;
		long long cur_divisor;
		long long cur_q;
        while(a >= b){
			cur_divisor = b;
			cur_q = 1;
			while(a >= cur_divisor){
				cur_divisor <<= 1;
				cur_q <<= 1;
			}
			cur_divisor >>= 1;
			cur_q >>= 1;
			q += cur_q;
			a -= cur_divisor;
		}
		
		if(pos)
            return q;
        return -q;
    }
};
