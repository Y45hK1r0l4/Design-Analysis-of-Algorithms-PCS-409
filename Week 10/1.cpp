
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void activitySelection(vector<int>& start, vector<int>& finish) {
    int n = start.size();
    vector<vector<int>> activities;

    for (int i = 0; i < n; i++) {
        activities.push_back({finish[i], start[i], i + 1});  
    }

    // Sort by finish time
    sort(activities.begin(), activities.end());

    int count = 0;
    int lastFinish = 0;
    vector<int> selected;

    for (auto activity : activities) {
        if (activity[1] >= lastFinish) {
            count++;
            selected.push_back(activity[2]);  
            lastFinish = activity[0];         
        }
    }

    cout << "No. of non-conflicting activities: " << count << endl;
    cout << "List of selected activities: ";
    for (int i = 0; i < selected.size(); i++) {
        cout << selected[i];
        if (i != selected.size() - 1) cout << ", ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<int> start(n), finish(n);

    cout << "Enter start times: ";
    for (int i = 0; i < n; i++) cin >> start[i];

    cout << "Enter finish times: ";
    for (int i = 0; i < n; i++) cin >> finish[i];

    activitySelection(start, finish);

    return 0;
}
