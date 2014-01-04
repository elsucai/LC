class Solution {
	public:
		void helper(string start, unordered_set<string> &target, unordered_map<string, unordered_set<string> > &previous, vector<vector<string> > &ret, vector<string> &one_path){
			if(target.find(start) != target.end()){
				one_path.push_back(start);
				ret.push_back(one_path);
				one_path.pop_back();
				return;
			}
			
			unordered_set<string>::iterator it;
			one_path.push_back(start);
			for(it = previous[start].begin(); it != previous[start].end(); it++){
				helper(*it, target, previous, ret, one_path);
			}
			one_path.pop_back();
		}
		
		void back_track(string start, string end, unordered_map<string, unordered_set<string> > &previous, vector<vector<string> > &ret){
		    int s,e;
		    unordered_set<string> target;
		    target.insert(end);
			vector<string> one_path;
			helper(start, target, previous, ret, one_path);
			for(int i = 0; i < ret.size(); i++){
				for(s = 0, e = ret[i].size()-1; s < e; s++, e--){
					swap(ret[i][s], ret[i][e]);
				}
			}
		}

		vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
			bool found = false;
			unordered_set<string> cur;
			unordered_set<string> next;
			vector<vector<string> > ret;
			unordered_map<string, unordered_set<string> > previous;

			string cur_word;
			int size = start.size();

			if(start == end){
				vector<string> tmp;
				tmp.push_back(end);
				ret.push_back(tmp);
				return ret;
			}
		
			cur.insert(start);
			dict.erase(start);
            unordered_set<string>::iterator it;
            
			char ori;
			string ori_s;
			while(!cur.empty() && !found){
				// delete words in dict that also in cur
				for(it = cur.begin(); it != cur.end(); it++)
					dict.erase(*it);
			
				// push next level to next
				for(it = cur.begin(); it != cur.end(); it++){
					cur_word = ori_s = *it;
					for(int i = 0; i < size; i++){
						ori = cur_word[i];
						for(char c = 'a'; c <= 'z'; c++){
						    if(c == cur_word[i])
						        continue;
							cur_word[i] = c;
							if(dict.find(cur_word) != dict.end()){
								next.insert(cur_word);
								if(previous.find(cur_word) == previous.end()){
									previous[cur_word] = unordered_set<string> ();
								}
								previous[cur_word].insert(ori_s);
							}
						}
						cur_word[i] = ori;
					}
				}
				cur.clear();
				if(next.find(end) != next.end())
				    found = true;
				swap(cur, next);
			}
			back_track(end, start, previous, ret);
			return ret;
		}
};

