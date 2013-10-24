class Solution {
public:
	
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
		if(ratings.size() == 1)
			return 1;
		int sum = 0;
		int size = ratings.size();
		vector<int> candy(size, 0);
		int i, s, e;
		for(s = e = 0; e < size; ){
			for(e = s+1; e < size; e++){
				// find non-decreasing sub sequences
				if(ratings[e] < ratings[e-1])
					break;
			}
			e--;
			if(s >= size)
				break;
			if(s-1 >= 0 && s-1 < size)
				candy[s] = candy[s-1]+1;
			else
				candy[s] = 1;
			for(i = s+1; i <= e; i++){
				if(ratings[i] == ratings[i-1])
					candy[i] = 1;
				else
					candy[i] = candy[i-1]+1;
			}
			
			// a non-increasing sub sequences begins or e >= size
			for(s = e+1, e = s+1; e < size; e++){
				if(ratings[e] > ratings[e-1])
					break;
			}
			e--;
			// [s -- e] is a non-increasing sub sequence
			if(s >= size)
				break;
			for(candy[e] = 1, i = e-1; i >= s; i--){
				if(ratings[i] == ratings[i+1])
					candy[i] = 1;
				else
					candy[i] = candy[i+1]+1;
			}
			if(s-1 >= 0 && s-1 < size){
				while(candy[s-1] <= candy[s])
					candy[s-1]++;
			}
			s = e+1;
		}
		for(i = 0; i < size; i++)
			sum += candy[i];
		return sum;
	}
};