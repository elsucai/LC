class Solution {
public:
    int longestConsecutive(vector<int> &num) {
		unordered_set<int> hs;
		for(int i = 0; i < num.size(); i++)
			hs.insert(num[i]);
		if(hs.empty())
			return 0;
		int cnt, maxcnt;
		cnt = maxcnt = 0;

		int center;
		while(!hs.empty()){
			center = *(hs.begin());
			hs.erase(center);
			cnt = 1;
			for(int inc = 1, inc < n; inc++){
				if(hs.find(center+inc) != hs.end()){
					cnt++;
					hs.erase(center+inc);
				}
				else
					break;
			}
			for(int inc = 1, inc < n; inc++){
				if(hs.find(center-inc) != hs.end()){
					cnt++;
					hs.erase(center-inc);
				}
				else
					break;
			}
			maxcnt = max(maxcnt, cnt);
		}
		return maxcnt;
    }
};
