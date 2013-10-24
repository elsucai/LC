class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		if(path.empty())
			return path;
		string ret = "";
		stack<string> s;
		for(int i = 0; i < path.size(); i++){
			if(s.empty() || (path.substr(i,1) != "/" && path.substr(i,1) != "."))
				s.push(path.substr(i,1));
			else if(path.substr(i,1) == "/"){
				if(s.empty())
					s.push(path.substr(i,1));
				else if(s.top() == "/")
					continue;
				else if(s.top() == "."){
					s.pop();
				}
				else
					s.push(path.substr(i,1));
			}
			else{
				//path.substr(i,1) == "."
				if(s.empty())
					s.push(path.substr(i,1));
				else if(s.top() == "."){
					s.pop();
					s.pop();
					while(!s.empty() && (s.top() != "/" && s.top() != "."))
						s.pop();
					if(s.empty()){
						// /.. = /
						s.push("/");
					}
				}
				else 
					s.push(path.substr(i,1));
			}
		}
		
		if(s.size() == 1)
			return s.top();
			
		while(s.size() > 1 && (s.top() == "/" || s.top() == "."))
			s.pop();
		while(!s.empty()){
			ret = s.top()+ret;
			s.pop();
		}
		return ret;
    }
};