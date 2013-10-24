class Solution {
public:
	struct S{
		int index;
		int val;
		S(int x, int y):index(x), val(y){}
	};
	
	static bool comp(S* a, S* b){
		return a->val < b->val;
	}
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ret;
		vector<S*> vs;
		S* tmp;
		for(int i = 0; i < numbers.size(); i++){
			tmp = new S(i, numbers[i]);
			vs.push_back(tmp);
		}
		sort(vs.begin(), vs.end(), comp);
		
		int sum, i, j;
		for(i = 0, j = vs.size()-1; i < j; ){
			sum = vs[i]->val + vs[j]->val;
			if(sum == target){
				ret.push_back(vs[i]->index+1);
				ret.push_back(vs[j]->index+1);
				if(ret[0] > ret[1])
					swap(ret[0], ret[1]);
				return ret;
			}
			if(sum < target)
				i++;
			else
				j--;
		}
		return ret;
    }
};