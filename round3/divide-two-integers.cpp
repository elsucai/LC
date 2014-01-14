class Solution {
public:
    int divide(int dividend, int divisor) {
		if(divisor == 0)
			return dividend >= 0 ? INT_MAX : INT_MIN;
		if(dividend == 0)
			return 0;
		int aflag = dividend > 0 ? 1 : -1;
		int bflag = divisor > 0 ? 1 : -1;
		int flag = aflag * bflag;
		long long a = (long long)dividend * aflag;
		long long b = (long long)divisor * bflag;

		if(b == 1)
			return (int)(a * flag);
		
		int quotient = 0;
		int i = 0;

		while(a > 0){
			i = 0;
			while(a >= (b<<i))
				i++;
			i--;
			if(i == -1)
				return flag*quotient;
			quotient += (1<<i);
			a -= (b<<i);
		}
		return flag*quotient;
    }
};
