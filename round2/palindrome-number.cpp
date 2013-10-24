class Solution {
public:
    bool isPalindrome(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		
		int l, r, div;

		if(x < 0)
			return false;

		div = 1;
		while(x / div >= 10){
			div *= 10;	
		}

		// x / div is a single digit

		while(x > 0){
			l = x / div;
			r = x % 10;
			if(l != r)
				return false;
			x = (x % div) / 10;
			div /= 100;
		}

		return true;
    }
};
