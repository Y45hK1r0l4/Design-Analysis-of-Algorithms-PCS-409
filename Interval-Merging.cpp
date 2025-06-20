#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};

    // Step 1: Sort intervals by start time
    sort(intervals.begin(), intervals.end());

    // Step 2: Initialize result with first interval
    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    // Step 3: Traverse and merge
    for (int i = 1; i < intervals.size(); ++i) {
        vector<int>& last = merged.back();         // Last interval in result
        vector<int>& current = intervals[i];       // Current interval

        if (current[0] <= last[1]) {               // Overlapping
            last[1] = max(last[1], current[1]);    // Merge
        } else {
            merged.push_back(current);             // No overlap
        }
    }

    return merged;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = mergeIntervals(intervals);

    cout << "Merged Intervals:\n";
    for (auto& interval : result)
        cout << "[" << interval[0] << ", " << interval[1] << "]\n";

    return 0;
}
