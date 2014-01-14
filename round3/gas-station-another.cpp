class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		if(gas.size() <= 0)
			return -1;
		vector<int> remain;
		int n = gas.size();
		int i, s, r;
		int min_index, min_tank;

		min_index = min_tank = 0;
		for(r = 0, i = 1; i < n; i++){
			r += gas[i-1] - cost[i-1];
			if(r < min_tank){
				min_index = i;
				min_tank = r;
			}
		}
		// test if min_index if valid
		int sum = 0;
		int cnt = 0;
		for(i = min_index; cnt < n; cnt++, i = (i+1)%n){
			sum += gas[i] - cost[i];
			if(sum < 0)
				return -1;
		}
		return min_index;
    }
};
