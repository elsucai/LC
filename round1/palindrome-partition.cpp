class Solution {
public:
	
	void helper(vector<vector<string> > &ret, string &str, vector<vector<bool> > &is_palindrome, vector<string> &one_partition, int s, int e){
		if(s > e){
			ret.push_back(one_partition);
			return;
		}
		for(int i = s; i <= e; i++){
			if(is_palindrome[s][i]){
				one_partition.push_back(str.substr(s, i-s+1));
				helper(ret, str, is_palindrome, one_partition, i+1, e);
				if(!one_partition.empty())
					one_partition.pop_back();
			}
		}
	}

    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       vector<vector<string> > ret;
       
       if(s.empty())
       	   return ret;
       
       int size = s.size();
       int i, j;
       vector<vector<bool> > is_palindrome(size, vector<bool>(size, false));
       
       for(i = 0; i < size; i++)
           is_palindrome[i][i] = true;
       
       for(i = size-2; i >= 0; i--){	
       	   is_palindrome[i][i+1] = (s[i] == s[i+1]);
       	   for(j = i+2; j < size; j++){
       	       is_palindrome[i][j] = is_palindrome[i+1][j-1] && (s[i] == s[j]);
       		}
       }
       
       vector<string> one_partition;
       helper(ret, s, is_palindrome, one_partition, 0, size-1);
       
       return ret;
    }
};
