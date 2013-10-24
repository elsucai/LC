class Solution {
public:
    int jump(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		
		// try one step at a time
		if(n <= 1)
			return 0;
		
		int start, fur, cur_fur, step;
		step = 0;
		fur = -1;
		cur_fur = 0;
		start = 0;

		int i;
		while(start < n && start <= cur_fur){
			for(i = start; i <= cur_fur; i++){
			
				if(i + A[i] >= n-1)
					return step+1;
				
				if(fur < i+A[i])
					fur = i+A[i];
				if(fur > n-1)
					fur = n-1;
			}
			step++;
			start = cur_fur+1;
			cur_fur = fur;
		}

		return INT_MAX;
    }
};
