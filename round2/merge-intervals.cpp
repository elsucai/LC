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
	static bool comp(Interval x, Interval y){
		return x.start < y.start;
	}
	
    vector<Interval> merge(vector<Interval> &intervals) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		if(intervals.size() <= 1)
			return intervals;
		sort(intervals.begin(), intervals.end(), comp);
		
		for(int i = 1; i < intervals.size(); i++){
			// try to merge intervals[i] and intervals[i-1]
			if(intervals[i].start <= intervals[i-1].end){
				intervals[i].start = intervals[i-1].start;
				intervals[i].end = max(intervals[i].end, intervals[i-1].end);
				
				intervals[i-1].end = 0;
				intervals[i-1].start = 1;
			}
		}
		
		for(int i = intervals.size()-1; i >= 0; i--){
			if(intervals[i].start > intervals[i].end)
				intervals.erase(intervals.begin()+i);
		}
		
		return intervals;
    }
};