class Solution {
public:
    int singleNumber(int A[], int n) {
		int one, two;
		one = two = 0;
		int tmp, cur;
		for(int i = 0 ; i < n; i++){
			cur = A[i];
			// find the bits that appear 3 times
			tmp = cur & two;
			two = two ^ tmp;
			cur = cur ^ tmp;

			// find the bits that appear 2 times
			tmp = cur & one;
			two = two | tmp;
			one = one ^ tmp;
			cur = cur ^ tmp;

			one = one | cur;
		}
		return one;
    }
};
