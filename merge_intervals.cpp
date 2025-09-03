// merge- intervals.cpp --- 56


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         if (intervals.size() <= 1) 
        return intervals;

    // Sort by ascending starting point
    sort(intervals.begin(), intervals.end(), 
         [](const vector<int>& a, const vector<int>& b) {
             return a[0] < b[0];
         });

    vector<vector<int>> result;
    vector<int> newInterval = intervals[0];
    result.push_back(newInterval);

    for (const auto& interval : intervals) {
        if (interval[0] <= newInterval[1]) {
            // Overlapping intervals, update the end if needed
            newInterval[1] = max(newInterval[1], interval[1]);
            result.back() = newInterval;  // update last added
        } else {
            // Disjoint intervals, add new interval
            newInterval = interval;
            result.push_back(newInterval);
        }
    }
return result;
        
    }
};