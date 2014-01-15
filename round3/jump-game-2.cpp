class Solution {
public:
    int jump(int A[], int n) {
		if(n <= 1)
			return 0;
		int moved, furthest, cur_f, start, stop;
		furthest = cur_f = start = stop = 0;
		for(moved = 0; moved <= n-1; moved++){
			stop = min(n-1, furthest);
			for(; start <= stop; start++){
				if(start == n-1)
					return moved;
				if(start + A[start] >= n-1)
					return moved+1;
				cur_f = max(cur_f, start + A[start]);
			}
			if(furthest == cur_f){
				// can not go further
				return -1;
			}
			start = furthest+1;
			furthest = cur_f;
		}
		return -1;
    }
};
