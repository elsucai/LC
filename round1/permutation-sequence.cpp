class Solution {
public:

	int find_last_occurance(string& ret, char val, int s, int e){
		int candidate = -1;
		if(s > e)
			return candidate;
		int m;
		while(s <= e){
			m = s + (e - s)/2;
			if(ret[m] == val){
				candidate = max(candidate, m);
				s = m+1;
			}
			else if(ret[m] < val)
				e = m-1;
			else
				s = m+1;
		}
		if(candidate = -1)
			return e;
	}

	void get_next_perm(string &ret, int size){
		int i, j;
		if(size <= 1)
			return;

		for(j = size-2; j >= 0; j--){
			if(ret[j] < ret[j+1])
				break;
		}
		if(j < 0){
			// reverse the string
			// if this happens, we already reached the last string
			// which means k > n!
			// shouldn't happen
			return;
		}

		i = find_last_occurance(ret, (char)(ret[j]+1), j+1, size-1);
		swap(ret[i], ret[j]);
		for(j = j+1, i = size-1; j < i; j++, i--)
			swap(ret[i], ret[j]);
	}


	void helper(string& ret, int size, int k){
		int d,p,r;
		int s,e,next;
		int i,j;
		s = 0;
		e = size-1;
		while(true){
			if(k == 1)
				return;
			d = 1;
			p = 1;
			next = 2;
			while(p*next <= k){
				p *= next;
				d++;
				next++;
			}
			r = k - p;
			for(i = e-d+1, j = e; i < j; i++, j--)
				swap(ret[i], ret[j]);
			if(r == 0)
				return;
			
			get_next_perm(ret, size);
			k = r;
			s = e-d;
		}
	}

    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    
		int max = 1;
		for(int i = n; i >= 2; i--)
			max *= i;
		if(k > max)
			return "";

		string ret = "123456789";
		ret = ret.substr(0, n);
		helper(ret, n, k);
		return ret;

/*
		for(int i = 2; i <= k; i++)
			get_next_perm(ret, n);

		return ret;
*/
    }
};
