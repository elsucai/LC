class Solution {
public:
    bool isPalindrome(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		if(x < 0)
			return false;
        
        if(x <= 9)
            return true;
            
        int digits = floor(log10(x));
		int div = pow(10, digits);
		
		//while(x/div >= 10)
		//	div *= 10;

		int first, last;
		while(x > 0){
			first = x/div;
			last = x%10;
			if(first != last)
				return false;
			x %= div;
			x /= 10;
			div /= 100;
		}
		return true;
    }
};
