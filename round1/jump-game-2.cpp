class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		int furthest = 0;
		int start = 0;
		int step = 0;
		if(n <= 0)
			return -1;
		if(n == 1)
			return 0;

		// see if 1 step is enough
		// if not, increase step one at a time
		for(step = 1; step <= n-1; step++){
			int cur_furthest = furthest;
			for(; start <= cur_furthest; start++){
				if(start + A[start] >= n - 1)
					return step;
				furthest = max(furthest, start+A[start]);
				if(furthest > n - 1)
					furthest = n-1;
			}
		}
		return -1;
	}
};
