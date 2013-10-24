/*
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
*/
class Solution {
public:
	void push_all_neighbors(unordered_set<string> &dict, vector<string> &words, unordered_map<string, int> &word2index, unordered_set<int> &visited, queue<vector<int> > &Qindex, queue<int> &Qlevel, vector<int> &indextmp, int curindex, int curlevel, int result_level){
		string curstr = words[curindex];
		vector<int> tmp;
		int size = curstr.size();
		char ori;
		for(int i = 0; i < size; i++){
			ori = curstr[i];
			for(char x = 'a'; x <= 'z'; x++){
				if(x == ori)
					continue;
				curstr[i] = x;
				if(dict.find(curstr) != dict.end() && (visited.find(curstr) == visited.end() || curlevel+1 <= result_level)){
					tmp.clear();
					for(int j = 0; j < indextmp.size(); j++){
						tmp.push_back(indextmp[j]);
					}
					tmp.push_back(word2index[curstr]);
					Qindex.push(tmp);
					Qlevel.push(curlevel+1);
				}
			}
			curstr[i] = ori;
		}
	}

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		vector<string> strtmp;
		vector<int> indextmp;
		vector<vector<string> >ret;
		queue<vector<int> > Qindex;
		queue<int> Qlevel;
		
		vector<string> words;
		unordered_map<string, int> word2index;
		unordered_set<int> visited;
		
		if(start == end && dict.find(start) != dict.end()){
			strtmp.push_back(start);
			ret.push_back(strtmp);
			return ret;
		}
		
		unordered_set<string>::iterator it;
		int i, j, size;
		for(i = 0, it = dict.begin(); it != dict.end(); i++, it++){
			words.push_back(*it);
			word2index[*it] = i;
		}
		size = words.size();

		// now do BFS
		
		indextmp.push_back(word2index[start]);
		Qindex.push(indextmp);
		Qlevel.push(1);
		
		int curlevel;
		int curindex;
		int result_level = size;
		
		while(!Qindex.empty()){
			indextmp = Qindex.front();
			curindex= indextmp.back();
			curlevel = Qlevel.front();
			Qindex.pop();
			Qlevel.pop();
			
			visited.insert(curindex);
			
			if(curindex == word2index[end]){
				strtmp.clear();
				for(i = 0; i < indextmp.size(); i++){
					strtmp.push_back(words[indextmp[i]]);
				}
				ret.push_back(strtmp);
				result_level = curlevel;
			}
			else{
					// push all neighbors
					push_all_neighbors(dict, words, word2index, visited, Qindex, Qlevel, indextmp, curindex, curlevel, result_level);
				}
		}
		return ret;
    }
};
/*
int main(){
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("cog");
	dict.insert("dog");
	dict.insert("tot");
	dict.insert("hog");
	dict.insert("hop");
	dict.insert("pot");
	dict.insert("dot");

	Solution s;
	vector<vector<string> >ret = s.findLadders("hot", "dog", dict);
	for(int i = 0; i < ret.size(); i++){
		for(int j = 0; j < ret[i].size(); j++)
			cout<<ret[i][j]<<" , ";
		cout<<endl;
	}
	return 0;
}
*/
