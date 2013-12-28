class Solution {
	public:
		int find_kth_smallest(int* A, int as, int ae, int* B, int bs, int be, int k){
			// return kth smallest in union AB
			int am, bm, target, leftsize;
			int bs_tmp, be_tmp;
			while(1){
				ae = min(ae, as+k-1);
				be = min(be, bs+k-1);

				if(as > ae){
					if(bs+k-1 <= be)
						return B[bs+k-1];
					return -1;
				}
				if(bs > be){
					if(as+k-1 <= ae)
						return A[as+k-1];
					return -1;
				}

				am = as + (ae - as)/2;
				target = A[am];

				bs_tmp = bs;
				be_tmp = be;
				while(bs_tmp <= be_tmp){
					bm = bs_tmp + (be_tmp - bs_tmp)/2;
					if(B[bm] == target)
						break;
					if(B[bm] < target)
						bs_tmp = bm + 1;
					else
						be_tmp = bm - 1;
				}
				if(be_tmp < bs_tmp)
					bm = be_tmp;

				leftsize = am-as+1+bm-bs+1;
				if(leftsize == k)
					return target;
				if(leftsize < k){
					as = am+1;
					bs = bm+1;
					k = k-leftsize;
				}
				else{
					//leftsize > k
					ae = am-1;
					be = bm;
				}
			}
		}

		double findMedianSortedArrays(int A[], int m, int B[], int n) {
			int k = (m+n)/2+1;
			int kth = find_kth_smallest(A, 0, m-1, B, 0, n-1, k);
			if((m&1)^(n&1))
				return kth;

			// m+n is even
			kth += find_kth_smallest(A, 0, m-1, B, 0, n-1, k-1);
			return (double)kth/2.0;
		}
};
