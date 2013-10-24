class Solution {
public:
	int find(int a[], int val, int i, int j){
		// find a[x] == val
		// if no such val, return the index of the element closest to val, and less than val
		int m;
		while(i <= j){
			m = i + (j - i)/2;
			if(a[m] == val)
				return m;
			if(a[m] < val)
				i = m+1;
			else
				j = m-1;
		}
		return j;
	}

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       
		int as, ae, bs, be, am, bm, curleft, next;
		as = bs = 0;
		ae = m-1;
		be = n-1;

		int left = (m+n+1)/2;
		bool odd = (m+n)%2 == 1;
    
		while(as <= ae && bs <= be){
			am = as+(ae - as)/2;
			bm = find(B, A[am], bs, be);

			curleft = am - as + 1;
			if(bm != -1){
				curleft += (bm - bs + 1);
			}

			if(curleft == left){
				//found median
				if(odd)
					return A[am];
				next = INT_MAX;
				if(am+1 <= ae)
					next = A[am+1];
				if(bm+1 <= be)
					next = min(next, B[bm+1]);
				return (A[am] + next)/2.0;
			}
			if(curleft < left){
				as = am + 1;
				bs = bm + 1;
				left -= curleft;
			}
			else{
				ae = am-1;
				be = bm;
			}
		}

		if(as <= ae){
			am = as + left - 1;
			if(odd)
				return A[am];
			return (A[am] + A[am+1])/2.0;
		}
		else if(bs <= be){
			bm = bs + left - 1;
			if(odd)
				return B[bm];
			return (B[bm] + B[bm+1])/2.0;
		}
		else
			return 0;
	}
};
