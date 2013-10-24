/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    
	int bs (vector<Interval> &intervals, int val){
		// return index of intervals that has a start value less than val
		// handle index of -1, n
		int i = 0; 
		int j = intervals.size()-1;
		int m;
		while(i <= j){
			m = i + (j - i)/2;
			if(intervals[m].start == val)
				return m;
			if(intervals[m].start < val)
				i = m + 1;
			else
				j = m - 1;
		}
		// j is the one
		if(j < 0)
			j = 0;

		return j;
	}
	
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		vector<Interval> ret;
		if(intervals.empty()){
			ret.push_back(newInterval);
			return ret;
		}

		int size = intervals.size();
		int left = newInterval.start;
		int right = newInterval.end;

		int L = bs(intervals, left);
		int R = bs(intervals, right);

		if(left > intervals[L].end)
			L++;
		if(L > R){
			//insert after intervals[R]
			for(int i = 0; i <= R; i++)
				ret.push_back(intervals[i]);
			ret.push_back(newInterval);
			for(int i = R+1; i < size; i++)
				ret.push_back(intervals[i]);
			return ret;
		}

		if(right < intervals[L].start){
			// newInterval goes first
			ret.push_back(newInterval);
			for(int i = 0; i < size; i++)
				ret.push_back(intervals[i]);
			return ret;
		}

        newInterval.start = min(intervals[L].start, left);
        newInterval.end = max(intervals[R].end, right);
		//insert 0 - (L-1), newinterval, R+1 -- size-1
		for(int i = 0; i <= L-1; i++)
			ret.push_back(intervals[i]);
		ret.push_back(newInterval);
		for(int i = R+1; i < size; i++)
			ret.push_back(intervals[i]);
		return ret;
    }
};
