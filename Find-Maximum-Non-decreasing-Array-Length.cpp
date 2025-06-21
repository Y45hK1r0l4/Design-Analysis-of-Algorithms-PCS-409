#include <iostream>
#include <vector>
using namespace std;

int longestDescendingSubarray(const vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;

    int maxLen = 1, currLen = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            currLen++;
        } else {
            currLen = 1;  // reset on break
        }
        maxLen = max(maxLen, currLen);
    }

    return maxLen;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int result = longestDescendingSubarray(arr);
    cout << "Max length of descending subarray = " << result << endl;

    return 0;
}
