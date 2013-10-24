class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		
		unordered_set<int> hs;
		
		for(int i = 0; i < num.size(); i++)
			hs.insert(num[i]);

		int maxlen = 0;
		int curlen = 0;
		int curnum;
		int test;

		while(!hs.empty()){
			curlen = 0;
			test = curnum = *hs.begin();
			while(hs.find(test) != hs.end()){
				curlen++;
				hs.erase(test);
				test++;
			}

			test = curnum-1;
			while(hs.find(test) != hs.end()){
				curlen++;
				hs.erase(test);
				test--;
			}

			// update global maxlen
			if(maxlen < curlen)
				maxlen = curlen;
		}

		return maxlen;
    }
};
