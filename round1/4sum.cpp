class Solution {
public:
    struct element{
		int i;
		int j;
		int sum;
		element(int x, int y, int z):i(x), j(y), sum(z) {}
	};
	
	static bool comp(element* a, element* b){
		return a->sum < b->sum;
	}
	
	void push_to_holder(map<vector<int> >&holder, vector<int> &num, vector<element*> &arr, int s1, int e1, int s2, int e2){
		if(arr[i]->i == arr[j]->i || arr[i]->i == arr[j]->j || arr[i]->j == arr[j]->i || arr[i]->j == arr[j]->j){
			i++;
			continue;
		}
		// push to holder
		tmp.clear();
		tmp.push_back(num[arr[i]->i]);
		tmp.push_back(num[arr[i]->j]);
		tmp.push_back(num[arr[j]->i]);
		tmp.push_back(num[arr[j]->j]);
		sort(tmp.begin(),tmp.end());
		holder.insert(tmp);
	}
	
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		// 4sum O(n^2logn) complexity
		vector<vector<int>> ret;
		vector<element*> arr;
		set<vector<int> > holder;
		
		int size = num.size();
		if(size < 4)
			return ret;
		
		int i, j, x, y;
		for(i = 0; i < size; i++){
			for(j = i+1; j < size; j++){
				arr.push_back(new element(i, j, num[i]+num[j]));
			}
		}
		int newsize = arr.size();
		sort(arr.begin(), arr.end(), comp);
		
		int sum;
		int s1, s2, e1, e2;
		for(i = 0, j = newsize-1; i < j; ){
			sum = arr[i]->sum + arr[j]->sum;
			if(sum == target){
				for(s1 = e1 = i; arr[e1]->sum == arr[s1]->sum; e1++)
				
				i++;
			}
			else if(sum < target)
				i++;
			else
				j--;
		}
		
		
        set<vector<int> >::iterator it;
		for(it = holder.begin(); it != holder.end(); it++){
			ret.push_back(*it);
		}
		
		return ret;
    }
};