#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<char> arr(n);
    unordered_map<char, int> freq;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        freq[arr[i]]++;  // Hashing in O(1)
    }

    // Extract keys into a vector and sort
    vector<char> unique_chars;
    for (auto &pair : freq) {
        unique_chars.push_back(pair.first);
    }

    sort(unique_chars.begin(), unique_chars.end());

    for (char ch : unique_chars) {
        cout << ch << " " << freq[ch] << endl;
    }

    return 0;
}
