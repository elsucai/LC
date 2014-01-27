class Solution {
public:
    string simplifyPath(string path) {
		stack<string> s;
		if(path.empty())
			return path;
		if(path[0] == '/'){
			s.push("/");
			path = path.substr(1, path.size()-1);
		}
		
		stringstream ss(path);
		string token;
		while(getline(ss, token, '/')){
			if(token.empty() || token == ".")
				continue;
			if(token == ".."){
				if(s.empty() || s.top() == "..")
					s.push(token);
				else if(s.top() == "/")
					continue;
				else
					s.pop();
			}
			else
				s.push(token);
		}
		string ret = "";
		if(s.empty())
			return ret;
		ret = s.top();
		s.pop();
		if(s.empty())
			return ret;
			
		while(s.size() > 1){
			ret = s.top()+"/"+ret;
			s.pop();
		}
		if(s.top() == "/")
			ret = "/"+ret;
		else
			ret = s.top()+"/"+ret;
		s.pop();
		return ret;
    }
};
