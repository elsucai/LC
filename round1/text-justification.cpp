class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<string> ret;
		int n = words.size();
		int s, i, j, cnt;
		int extra, totalspace;
		string line = "";
		int curlen = 0;
		int r;
		
		s = 0;
		
		while(s < n){
			cnt = curlen = 0;
			line = "";
			for(i = s; i < n; i++){
				if(curlen + words[i].size() > L)
					break;
				cnt++;
				curlen += words[i].size();
				curlen++;
			}
			
			curlen--;
			totalspace = L - curlen;
			
			if(i == n){
				// last line
				for(j = s; j < s+cnt; j++){
					line += words[j];
					line += " ";
				}
				line = line.substr(0, line.size()-1);
				for(int k = 0; k < totalspace; k++)
					line += " ";
					
				ret.push_back(line);
				return ret;
			}
			
			// not the last line
			if(cnt == 1){
				extra = totalspace;
                line += words[s];
				for(int k = 0; k < extra; k++)
					line += " ";
			}
			else{
				extra = totalspace/(cnt-1);
				r = totalspace%(cnt-1);
				
				for(j = s; j < s+cnt-1; j++){
					line += words[j];
					line += " ";
					for(int k = 0; k < extra; k++)
					line += " ";
					if(r > 0){
						line += " ";
						r--;
					}
				}
				// last word
				line += words[j];
			}
            ret.push_back(line);
			s += cnt;
		}
		return ret;
	}
};