class Solution {
	public:
		int ladderLength(string start, string end, unordered_set<string> &dict) {
			int size = start.size();
			queue<string> q;
			queue<int> level;
			unordered_set<string> visited;

			visited.insert(start);
			q.push(start);
			level.push(1);

			string cur_s;
			int cur_l;
			char ori;
			while(!q.empty()){
				cur_s = q.front();
				cur_l = level.front();
				q.pop();
				level.pop();
				if(cur_s == end)
					return cur_l;
				for(int i = 0; i < size; i++){
					ori = cur_s[i];
					for(int c = 'a'; c <= 'z'; c++){
						cur_s[i] = c;
						if(dict.find(cur_s) != dict.end() && visited.find(cur_s) == visited.end()){
							visited.insert(cur_s);
							q.push(cur_s);
							level.push(cur_l+1);
							if(cur_s == end)
								return cur_l+1;
						}
					}
					cur_s[i] = ori;
				}
			}
			return 0;
		}
};
