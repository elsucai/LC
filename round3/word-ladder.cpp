class Solution {
	public:
		int ladderLength(string start, string end, unordered_set<string> &dict) {
			int size = start.size();
			queue<string> cur_level;
			queue<string> next_level;
			int level = 1;
			cur_level.push(start);
			dict.erase(start);
			string cur;
			char c;

			while(!cur_level.empty()){
				while(!cur_level.empty()){
					cur = cur_level.front();
					cur_level.pop();
					for(int i = 0; i < size; i++){
						c = cur[i];
						for(int x = 'a'; x <= 'z'; x++){
							cur[i] = (char)x;
							if(cur == end)
								return level+1;
							if(dict.find(cur) != dict.end()){
								dict.erase(cur);
								next_level.push(cur);
							}
						}
						//	revert back to original string
						cur[i] = c;
					}
				}
				// the next level is filled
				level++;
				swap(cur_level, next_level);
			}
			return 0;
		}
};
