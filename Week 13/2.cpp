#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool hasDuplicateInWindow(vector<int>& arr, int k) {
    unordered_set<int> window;

    for (int i = 0; i < arr.size(); ++i) {
        if (window.find(arr[i]) != window.end()) {
            return true; // Duplicate found in window
        }

        window.insert(arr[i]);

        // Maintain window size
        if (i >= k) {
            window.erase(arr[i - k]);
        }
    }

    return false; // No duplicate found in any window of size k
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        cin >> k;

        if (hasDuplicateInWindow(arr, k)) {
            cout << "Duplicate present in window " << k << "." << endl;
        } else {
            cout << "Duplicate not present in window " << k << "." << endl;
        }
    }

    return 0;
}
