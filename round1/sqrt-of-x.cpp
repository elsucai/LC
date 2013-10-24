#include <stdio.h>

// find the root of function ret*ret = x
// here we try f(ret) = ret*ret - x
// f'(ret) = 2*ret

class Solution {
public:

    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

	assert(x >= 0);
        double delta = 0.00001;
	double ret = 1;
	
	while(abs(ret*ret - x) > delta){
		// new_x = old_x - f(old_x)/f'(old_x) = old_x - (old_x^2 - t)/2/x
		ret = ret - (ret*ret-x)/(2*ret);
	}
	
	return (int) ret;
    }
};
