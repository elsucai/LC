class Solution {
public:
	string gen_next(string &s){
		string ret = "";
		char cur = s[0];
		int cnt = 0;
		int size = s.size();
		int i;
		for(i = 0; i < size;){
			while(i < size && s[i] == cur){
				cnt++;
				i++;
			}
			ret += to_string(cnt);
			ret += cur;
			cnt = 0;
			if(i < size)
				cur = s[i];
		}
		return ret;
	}

    string countAndSay(int n) {
		string cur = "1";
		if(n == 1)
			return cur;
		
		for(int i = 1; i < n; i++)
			cur = gen_next(cur);
		return cur;
    }
};
