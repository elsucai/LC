class Solution {
public:

	bool push_neighbor(queue<string> &Qs, queue<int> &Qi, vector<unordered_set<char> > &words, unordered_set<string> &dict, unordered_set<string> &target, string cur, int cur_level){

		unordered_set<char>::iterator it;
		char ori;
		int size = cur.size();

		for(int i = 0; i < size; i++){
			ori = cur[i];
			for(it = words[i].begin(); it != words[i].end(); it++){
				if(*it != ori){
					cur[i] = *it;
					//cur has changed to its next neighbor
					if(target.find(cur) != target.end())
						return true;
					if(dict.find(cur) == dict.end()){
						// not in the word list
						continue;
					}
					else{
						// push to queue and delete in dict
						Qs.push(cur);
						Qi.push(cur_level+1);
						dict.erase(cur);
					}
				}
				else
					continue;
			}
			cur[i] = ori;
		}
		return false;
	}

    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		int cur_level;
		string cur;
		queue<string> Qs;
		queue<int> Qi;
		unordered_set<string> target;
		vector<unordered_set<char> > words;
		unordered_set<string>::iterator it;

		if(start.size() != end.size())
			return 0;
		if(dict.find(start) == dict.end() || dict.find(end) == dict.end())
			return 0;
		if(start == end)
			return 1;
		
		Qs.push(start);
		Qi.push(1);
		dict.erase(start);
		target.insert(end);

		// initialize words
		int wsize = *(dict.beign()).size();
		for(int i = 0; i < wsize; i++){
			unordered_set<char> tmp;
			words.push_back(tmp);
		}


		for(it = dict.begin(); it != dict.end(); it++){
			cur = *it;
			for(int i = 0; i < wsize; i++)
				words[i].insert(cur[i]);
		}

		while(!Qs.empty()){
			cur = Qs.front();
			cur_level = Qi.front();
			Qs.pop();
			Qi.pop();
	
			if(push_neighbor(Qs, Qi, words, dict, target, cur, cur_level))
				return cur_level+1;
		}

		return 0;
    }
};
