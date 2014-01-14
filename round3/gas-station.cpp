class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		if(gas.size() <= 0)
			return -1;
		vector<int> remain;
		int n = gas.size();
		int i, s, e, sum, tested, step;
		for(i = 0; i < n; i++)
			remain.push_back(gas[i] - cost[i]);
	
		s = e = sum = tested = step = 0;
		for(; step < n && tested < n; ){
			sum += remain[e];
			while(sum < 0){
				sum -= remain[s];
				tested++;
				s = (s+1)%n;
				step--;
			}
			e = (e+1)%n;
			step++;
		}
		if(step == n)
			return s;
		return -1;
    }
};
