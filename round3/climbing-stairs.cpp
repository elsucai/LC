class Solution {
public:
    int climbStairs(int n) {
		int a = 1;
		int b = 1;
		int c;
		if(n <= 1)
			return 1;
		for(int i = 2; i <= n; i++){
			c = a+b;
			a = b;
			b = c;
		}
		return c;
    }
};
