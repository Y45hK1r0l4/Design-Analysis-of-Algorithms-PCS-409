#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.first.second < b.first.second; // sort by deadline
}

void jobSequencing(vector<int>& time, vector<int>& deadline){
    vector<pair<pair<int, int>, int>> tasks;
    int n = time.size();

    for(int i = 0; i < n; i++) {
        tasks.push_back({{time[i], deadline[i]}, i + 1});
    }

    // Sort tasks by deadline
    sort(tasks.begin(), tasks.end(), compare);

    int currentTime = 0;
    vector<int> selected;

    for (auto task : tasks) {
        int t = task.first.first;
        int d = task.first.second;
        int index = task.second;

        if (currentTime + t <= d) {
            currentTime += t;
            selected.push_back(index);
        }
    }

    cout << "Max number of tasks = " << selected.size() << endl;
    cout << "Selected task numbers : ";
    for (int id : selected) cout << id << " ";
    cout << endl;


}

int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<int> profit(n), deadline(n);

    cout << "Enter profits: ";
    for(int i = 0; i < n; i++) cin >> profit[i];

    cout << "Enter deadlines: ";
    for(int i = 0; i < n; i++) cin >> deadline[i];

    jobSequencing(profit, deadline);

    return 0;
}
