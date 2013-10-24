class Solution {
public:
	void twosum(vector<vector<int> > &sub, vector<int> &num, int target, int s, int e){
		if(s > e)
			return;
		int sum;
		vector<int> tmp;
		for(; s < e; ){
			sum = num[s] + num[e];
			if(sum == target){
				tmp.clear();
				tmp.push_back(num[s]);
				tmp.push_back(num[e]);
				sub.push_back(tmp);
				s++;
				while(s < e && num[s] == num[s-1])
					s++;
				e--;
				while(e > s && num[e] == num[e+1])
					e--;
			}
			else if(sum < target)
				s++;
			else
				e--;
		}
	}
	
	
    vector<vector<int> > threeSum(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		vector<vector<int> > ret;
		if(num.size() < 3)
			return ret;
		sort(num.begin(), num.end());
		int i, s, e;
		int size = num.size();
		vector<vector<int> > sub;
		for(i = 0; i < size-2; ){
			// num[i] is the first one
			sub.clear();
			twosum(sub, num, 0-num[i], i+1, size-1);
			if(!sub.empty()){
				for(int j = 0; j < sub.size(); j++){
					sub[j].insert(sub[j].begin(), num[i]);
					ret.push_back(sub[j]);
				}
			}
			i++;
			while(i < size-2 && num[i] == num[i-1])
				i++;
		}
		return ret;
    }
};