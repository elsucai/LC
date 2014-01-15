class Solution {
public:
    bool canJump(int A[], int n) {
		if(n <= 1)
			return true;
		int min_true_index = n-1;
		int i;
		for(i = n-2; i >= 0; i--){
			if(min_true_index <= i+A[i]){
				min_true_index = i;
			}
		}
		return min_true_index == 0;
    }
};
