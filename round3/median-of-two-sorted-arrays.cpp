class Solution {
public:
	int bsearch(int* arr, int s, int e, int val){
		int m;
		while(s <= e){
			m = s+(e-s)/2;
			if(arr[m] == val)
				return m;
			if(arr[m] < val)
				s = m+1;
			else
				e = m-1;
		}
		return e;
	}

	int helper(int A[], int as, int ae, int B[], int bs, int be, int k){
		if(as > ae)
			return B[bs+k-1];
		if(bs > be)
			return A[as+k-1];

		int am, bm;
		am = as+(ae-as)/2;
		bm = bsearch(B, bs, be, A[am]);
		
		int leftsize = am-as+1;
		
		if(bm >= bs){
			leftsize += bm-bs+1;
		}

		if(leftsize == k)
			return A[am];
		if(leftsize < k)
			return helper(A, am+1, ae, B, bm+1, be, k-leftsize);
		return helper(A, as, am-1, B, bs, bm, k);
	}

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int k = m+n;
		int k1 = k/2;
		int k2 = k/2+1;

		if(k == 0)
			return 0;

		int sk1, sk2;
		sk1 = sk2 = 0;

		// find smallest k2
		sk2 = helper(A, 0, m-1, B, 0, n-1, k2);

		if(k%2 == 0){
			// find smallest k1
			sk1 = helper(A, 0, m-1, B, 0, n-1, k1);
			return (double)(sk1+sk2)/2.0;
		}
		return (double)sk2;
    }
};
