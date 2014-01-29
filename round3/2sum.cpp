class Solution {
public:
	struct Pair{
		int val;
		int index;
		Pair(int a, int b):val(a), index(b){}
	};

	static bool comp(Pair *a, Pair *b){
		return a->val < b->val;
	}

    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        if(numbers.size() < 2)
            return ret;
		vector<Pair*> p;
		for(int i = 0; i < numbers.size(); i++){
			p.push_back(new Pair(numbers[i], i+1));
		}

        sort(p.begin(), p.end(), comp);
        int s, e, sum;
        for(s = 0, e = p.size()-1; s < e; ){
            sum = p[s]->val + p[e]->val;
            if(sum == target){
                ret.push_back(p[s]->index);
                ret.push_back(p[e]->index);
                if(ret[0] > ret[1])
                    swap(ret[0], ret[1]);
                return ret;
            }
            if(sum < target)
                s++;
            else
                e--;
        }
        return ret;
    }
};
