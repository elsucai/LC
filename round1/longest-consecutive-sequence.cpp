class Solution {
public:

	int find_consecutive(set<int> &hs, int n, int step){
		//find consecutive sequence starting with n
		int cnt = 0;
		while(hs.find(n) != hs.end()){
			hs.erase(n);
			cnt++;
			n += step;
		}
		return cnt;
	}

    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		if (num.empty())
			return 0;
		set<int> hs;
		for(int i = 0; i < num.size(); i++)
			hs.insert(num[i]);

		int max = 0;
		int cur;
		for(int i = 0; i < num.size(); i++){
			cur = find_consecutive(hs, num[i], 1);
			cur += find_consecutive(hs, num[i]-1, -1);
			if(max < cur)
				max = cur;
		}

		return max;
    }
};
