class Solution {
public:
	int helper(vector<int> &num, int target, int s, int e, int &offset){
		int global_offset = INT_MAX;
		int closest_sum;
		int cursum, cur_offset;
		for(; s < e; ){
			cursum = num[s]+num[e];
			cur_offset = abs(target - cursum);
			if(global_offset > cur_offset){
				global_offset = cur_offset;
				closest_sum = cursum;
			}
			if(cursum == target){
				offset = 0;
				return cursum;
			}
			if(cursum < target){
				s++;
				while(s < e && num[s] == num[s-1])
					s++;
			}
			else{
				e--;
				while(e > s && num[e] == num[e+1])
					e--;
			}
		}
		offset = global_offset;
		return closest_sum;
	}

    int threeSumClosest(vector<int> &num, int target) {
		int n = num.size();
		if(n < 3)
			return 0;
		int global_sum = 0;
		int global_offset = INT_MAX;
		int sum;
		int first;
		int offset;
		sort(num.begin(), num.end());
		for(first = 0; first <= n-3; ){
			sum = helper(num, target-num[first], first+1, n-1, offset);
			if(offset == 0){
				return sum+num[first];
			}
			if(global_offset > offset){
				global_offset = offset;
				global_sum = sum+num[first];
			}
			first++;
			while(first <= n-3 && num[first] == num[first-1])
				first++;
		}
		return global_sum;
    }
};
