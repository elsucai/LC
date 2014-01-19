class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		vector<int> ret = digits;
		if(ret.empty())
			return ret;
		int i;
		for(i = ret.size()-1; i >= 0 && ret[i] == 9; i--)
			;
		for(int j = i+1; j < ret.size(); j++){
			ret[j] = 0;
		}
		if(i < 0)
			ret.insert(ret.begin(), 1);
		else
			ret[i]++;
		return ret;
    }
};
