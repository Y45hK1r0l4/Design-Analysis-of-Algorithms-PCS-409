#include <iostream>
#include <vector>
using namespace std;

int countIncreasingSubarrays(const vector<int>& arr) {
    int n = arr.size();
    int count = 0, length = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1])
            length++;
        else {
            count += (length * (length + 1)) / 2;
            length = 1;
        }
    }

    count += (length * (length + 1)) / 2;  // last segment
    return count;
}

int main() {
    vector<int> arr = {1, 2, 3, 2, 4};
    cout << "Total strictly increasing subarrays: " << countIncreasingSubarrays(arr) << endl;
    return 0;
}
