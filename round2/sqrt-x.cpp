class Solution {
public:
    int sqrt(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        // use newton's method
		/*
		double delta = 0.000001;
		
		double a = 1;
		
		while(abs(a*a-x) > delta){
			a = a - (a*a-x)/2.0/a;
		}
		
		return int(a);
		*/
		
		// use binary search
		if(x == 0)
			return 0;
		int s, e, m;
		s = 1;
		e = x;
		int quotient;
		while(s <= e){
			m = s+(e-s)/2;
			quotient = x/m;
			if(quotient == m)
				return m;
			if(quotient > m)
				s = m+1;
			else
				e = m-1;
		}
		return e;
    }
};