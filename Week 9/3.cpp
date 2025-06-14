#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minComputationCost(vector<int>& files) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Push all file sizes into the min-heap
    for (int size : files) {
        minHeap.push(size);
    }

    int totalCost = 0;

    // Keep merging until one file remains
    while (minHeap.size() > 1) {
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();

        int merged = first + second;
        totalCost += merged;

        minHeap.push(merged);
    }

    return totalCost;
}

int main() {
    int n;
    cout << "Enter number of files: ";
    cin >> n;

    vector<int> files(n);
    cout << "Enter file sizes: ";
    for (int i = 0; i < n; i++) {
        cin >> files[i];
    }

    int cost = minComputationCost(files);
    cout << "Minimum computation cost: " << cost << endl;

    return 0;
}
