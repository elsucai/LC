class Solution {
public:
    int climbStairs(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n <= 2)
			return n;
		int a, b, c;
		a = 1;
		b = 2;
		
		for(int i = 3; i <= n; i++){
			c = a + b;
			a = b;
			b = c;
		}
		
		return c;
    }
};