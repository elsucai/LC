class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> >ret;
        vector<vector<int> >sub;
        int i;
        if(k <= 0 || n <= 0 || k > n)
            return ret;
        if(k == 1){
            for(i = 1; i <= n; i++)
                ret.push_back(vector<int>(1, i));
            return ret;
        }
        sub.clear();
        sub = combine(n-1, k);
        for(i = 0; i < sub.size(); i++)
            ret.push_back(sub[i]);
        sub.clear();
        sub = combine(n-1, k-1);
        
        for(i = 0; i < sub.size(); i++){
            sub[i].insert(sub[i].end(), n);
            ret.push_back(sub[i]);
        }
        return ret;
    }
};

class Solution {
	public:
		void helper(vector<vector<int> > &ret, vector<int> &one, int s, int e, int k){
			if(k == 0){
				ret.push_back(one);
				return;
			}
			if(s > e)
				return;
			// push current element
			one.push_back(s);
			helper(ret, one, s+1, e, k-1);
			one.pop_back();
			// skip current element
			helper(ret, one, s+1, e, k);
		}

		vector<vector<int> > combine(int n, int k) {
			vector<vector<int> > ret;
			vector<int> one;
			helper(ret, one, 1, n, k);
			return ret;
		}
};
