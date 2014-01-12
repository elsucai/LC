class Solution {
public:
    int firstMissingPositive(int A[], int n) {
		int i;
		for(i = 0; i < n; i++){
			while(A[i]-1 < n && A[i]-1 >= 0 && A[A[i]-1] != A[i]){
				swap(A[i], A[A[i]-1]);
			}
		}
		for(i = 0; i < n; i++){
			if(i+1 != A[i]){
				return i+1;
			}
		}
		return n+1;
    }
};
