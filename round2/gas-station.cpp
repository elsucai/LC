class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

		vector<int> r;
		int size = gas.size();
		for(int i = 0; i < size; i++){
			r.push_back(gas[i] - cost[i]);
		}

		int s, e, cnt, tries, sum;
		s = e = cnt = sum = 0;
		tries = 1;

		while(1){
			// find longest non negitive seq
			while(sum + r[e] >= 0){
				sum += r[e];
				cnt++;
				e = (e+1)%size;
				if(cnt == size){
					return s;
				}
			}
			sum += r[e];
			e = (e+1)%size;
			// a neqtive value found
			while(sum < 0){
				sum -= r[s];
				s = (s+1)%size;
				tries++;
				cnt--;
				if(tries > size){
					return -1;
				}
			}
		}
    }
};
