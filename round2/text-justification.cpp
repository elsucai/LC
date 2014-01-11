class Solution {
public:
	void push_line(vector<string> &ret, vector<string> &words, int s, int e, int len, int spaces, int L){
		int i, size;
		string line = "";
		if(e == words.size()-1){
			for(; s < e; s++)
				line += words[s]+" ";
			line += words[e];
			size = line.size();
			for(i = 1; i <= L-size; i++)
				line += " ";
			ret.push_back(line);
			return;
		}
		int extra = L - len;
		int cnt = e-s;
		if(cnt == 0){
			line += words[s];
			for(i = 1; i <= extra; i++)
				line += " ";
			ret.push_back(line);
			return;
		}
		int n = (spaces+extra)/cnt;
		int remain = (spaces+extra) % cnt;
		int x;
		for(i = s; i < e; i++){
			line += words[i];
			for(x = 1; x <= n; x++)
				line += " ";
			if(remain > 0){
				line += " ";
				remain--;
			}
		}
		line += words[e];
		ret.push_back(line);
	}

    vector<string> fullJustify(vector<string> &words, int L) {
		int s;
		int i;
		int len, spaces;
		int size = words.size();
		vector<string> ret;

		for(i = 0; i < size; ){
			len = spaces = 0;
			for(s = i; s < size; ){
				if(len + words[s].size()+1 <= L+1){
					len += words[s].size()+1;
					spaces++;
					s++;
				}
				else{
					len--;
					spaces--;
					break;
				}
			}
			push_line(ret, words, i, s-1, len, spaces, L);
			i = s;
		}
		return ret;
    }
};
