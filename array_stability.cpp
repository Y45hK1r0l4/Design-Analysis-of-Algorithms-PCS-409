#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int minDeletionsToMakeFrequenciesUnique(const vector<int>& arr) {
    unordered_map<int, int> freq;
    for (int num : arr)
        freq[num]++;

    set<int> usedFreq; // to store frequencies already used
    int deletions = 0;

    for (auto& [num, f] : freq) {
        while (f > 0 && usedFreq.count(f)) {
            f--;           // simulate deleting one occurrence
            deletions++;   // increase deletion count
        }
        if (f > 0)
            usedFreq.insert(f);
    }

    return deletions;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int result = minDeletionsToMakeFrequenciesUnique(arr);
    cout << "Minimum deletions to make all frequencies unique = " << result << endl;

    return 0;
}




#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int minDeletionsToMakeAllEqual(const vector<int>& arr) {
    unordered_map<int, int> freq;

    // Step 1: Count frequency of each element
    for (int num : arr)
        freq[num]++;

    // Step 2: Find max frequency
    int maxFreq = 0;
    for (auto& [num, count] : freq)
        maxFreq = max(maxFreq, count);

    // Step 3: Delete all others
    return arr.size() - maxFreq;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int result = minDeletionsToMakeAllEqual(arr);
    cout << "Minimum deletions to make all elements equal = " << result << endl;

    return 0;
}
