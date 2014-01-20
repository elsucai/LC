class Solution {
public:
	void reverse(string &ret, int x, int y){
		int i, j;
		for(i = x, j = y; i < j; i++, j--)
			swap(ret[i], ret[j]);
	}

	void helper(string &ret, int k ,int s, int e){
		int i, p;
		i = 2;
		p = 1;
		while(p*i <= k){
			p *= i;
			i++;
		}
		// p == (i-1)!
		i--;
		int cnt = k / p;
		int r = k % p;
		int x = e - i;
		int y = x+cnt-1;
		if(r == 0){
			swap(ret[x], ret[y]);
			sort(ret.begin()+x+1, ret.end());
			reverse(ret, x+1, e);
			return;
		}
		y++;
		swap(ret[x], ret[y]);
		sort(ret.begin()+x+1, ret.end());
		helper(ret, r, x+1, e);
	}

    string getPermutation(int n, int k) {
		string ret;
		for(int i = 1; i <= n; i++)
			ret += ('0'+i);
		helper(ret, k, 0, n-1);
		return ret;
    }
};
