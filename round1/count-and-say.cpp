class Solution {
public:

	string next(string cur){
		int s = 0;
		int e;
		int size = cur.size();
		string next = "";

		int count = 0;
		for(s = 0, e = s+1; e < size; ){
			while(cur[e] == cur[s])
				e++;
			count = e - s;
			next += to_string(count);
			next += cur.substr(s, 1);

			s = e;
			e++;
		}
		if(s < size){
			next += to_string(1);
			next += cur.substr(s, 1);
		}
		return next;
	}

    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(n <= 0)
			return "";
		string cur = "1";

		for(int i = 2; i <= n; i++)
			cur = next(cur);
		return cur;
    }
};
