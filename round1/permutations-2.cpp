class Solution {
public:
    // no duplications

	int find_last_occurance(vector<int> &num, int val, int s, int e){
		int candidate = -1;
		if(s > e)
			return candidate;
		int m;
		while(s <= e){
			m = s + (e - s)/2;
			if(num[m] == val){
				candidate = max(candidate, m);
				s = m+1;
			}
			else if(num[m] < val)
				e = m-1;
			else
				s = m+1;
		}
		if(candidate == -1)
			return e;
		return candidate;
	}


	void next_permutation(vector<int> &num, int size){
		// change num to its next permutation in place
		int i, j;
		for(i = size-2; i >= 0; i--){
			if(num[i] < num[i+1])
				break;
		}
		if(i < 0){
			// reverse the vecotor
			for(i = 0, j = size - 1; i < j; i++, j--)
				swap(num[i], num[j]);
			return;
		}

		// i is the element that less than num[i+1 ...]
		j = find_last_occurance(num, num[i]+1, i+1, size-1);
		swap(num[i], num[j]);
		//reverse the rest
		for(i = i+1, j = size-1; i < j; i++, j--)
			swap(num[i], num[j]);
	}
	
	vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		// implement get_next which returns the next permutation
		// of current one -- the next is lexicographically greater
		// than the previous. If the permutation reaches the greatest
		// revert to the smallest one

		// this algorithm is faster than the one commented out at the bottom
		vector<vector<int> >ret;
		if(num.empty())
			return ret;
		if(num.size() == 1){
			ret.push_back(num);
			return ret;
		}

		set<vector<int> > hs;	// which stores only the first permutation
		hs.insert(num);
        ret.push_back(num);
		int size = num.size();

		while(true){
			next_permutation(num, size);
			if(hs.find(num) == hs.end()){
				// put tmp to ret
				ret.push_back(num);
			}
			else
				return ret;
		}
    }

/*	
	void helper(set<vector<int> > &hs, vector<int> &num, int s, int e){
		vector<int> tmp;
		if(s > e){
			for(int i = 0; i <= e; i++)
				tmp.push_back(num[i]);
			if(hs.find(tmp) == hs.end())
				hs.insert(tmp);
			return;
		}

		for(int i = s; i <= e; i++){
			swap(num[s], num[i]);
			helper(hs, num, s+1, e);
			swap(num[s], num[i]);
		}
	}


    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<vector<int> >ret;
		if(num.empty())
			return ret;
		if(num.size() == 1){
			ret.push_back(num);
			return ret;
		}

		set<vector<int> > hs;
		set<vector<int> >::iterator it;
		helper(hs, num, 0, num.size()-1);
		// copy hs to vector
		for(it = hs.begin(); it != hs.end(); it++)
			ret.push_back(*it);
		return ret;
    }
*/
};
