class Solution {
public:
	struct S{
		int index;
		int val;
		S(int x, int y):index(x), val(y) {}
	};
	
	static bool comp(S* a, S* b){
		return a->val < b->val;
	}
	
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        S* tmp;
		int sum = 0;
		int size = ratings.size();
		vector<S*> helper;
		vector<int> candy(size, 1);
		
		for(int i = 0; i < ratings.size(); i++){
			tmp = new S(i, ratings[i]);
			helper.push_back(tmp);
		}
		sort(helper.begin(), helper.end(), comp);
		int curindex;
		for(int i = 0; i < size; i++){
			curindex = helper[i]->index;
			if(curindex - 1 >= 0 && ratings[curindex] < ratings[curindex - 1]){
				if(candy[curindex -1] <= candy[curindex])
					candy[curindex-1] = candy[curindex] + 1;
			}
			if(curindex + 1 < size && ratings[curindex] < ratings[curindex + 1]){
				if(candy[curindex + 1] <= candy[curindex])
					candy[curindex+1] = candy[curindex] + 1;
			}
		}
		
		for(int i = 0; i < size; i++)
			sum += candy[i];
		return sum;
	}
};
