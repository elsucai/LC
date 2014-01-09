class Solution {
public:
    void sortColors(int A[], int n) {
		// (left , s-1]: 0
		// [s , e] : unknown
		// (e , right) : 1
		int s = 0;
		int e = n-1;
		int i;
		for(i = s; i <= e; ){
			if(A[i] == 0){
				swap(A[s++], A[i++]);
			}
			else if(A[i] == 1)
				i++;
			else
				swap(A[i], A[e--]);
		}
    }
};
