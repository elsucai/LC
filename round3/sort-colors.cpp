class Solution {
public:
    void sortColors(int A[], int n) {
		int s, e, i;
		for(i = s = 0, e = n-1; i <= e; ){
			if(A[i] == 0){
				swap(A[s], A[i]);
				s++;
				i++;
			}
			else if(A[i] == 1){
				i++;
			}
			else{
				swap(A[i], A[e]);
				e--;
			}
		}
    }
};
