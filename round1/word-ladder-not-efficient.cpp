class Solution {
public:
    /*
	typedef struct _node{
		string key;
		int level;
		struct _node(string k, int l): key(k), level(l) {}
	}Node;
	*/
	bool is_neighbor(string a, string b){
		if(a.size() != b.size())
			return false;
		int size = a.size();
		int diff = 0;
		for(int i = 0; i < size; i++){
			if(a[i] != b[i]){
				diff++;
				if(diff > 1)
					return false;
			}
		}
		return true;
	}
			
	bool push_neighbor(queue<string> &Qs, queue<int> &Qi, vector<string> &words, unordered_set<string> &dict, unordered_set<string> &target, string cur, int cur_level){
		for(int i = words.size()-1; i >= 0; i--){
			if(!is_neighbor(cur, words[i]))
				continue;
			if(target.find(words[i]) != target.end()){
				return true;
			}

			// push to queue and delete in words
			Qs.push(words[i]);
			Qi.push(cur_level+1);

			words.erase(words.begin()+i);
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
		vector<string> words;
		unordered_set<string>::iterator it;

		if(start.size() != end.size())
			return 0;
		if(dict.find(start) == dict.end() || dict.find(end) == dict.end())
			return 0;
		
		Qs.push(start);
		Qi.push(1);
		dict.erase(start);
		for(it = dict.begin(); it != dict.end(); it++){
			words.push_back(*it);
		}
		target.insert(end);

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
