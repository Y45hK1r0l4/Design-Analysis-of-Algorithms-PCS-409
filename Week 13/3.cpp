#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int, pair<int, int>> productMap;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int prod = arr[i] * arr[j];

            if (productMap.find(prod) != productMap.end()) {
                pair<int, int> prev = productMap[prod];
                // Make sure all elements are distinct
                if (prev.first != arr[i] && prev.first != arr[j] &&
                    prev.second != arr[i] && prev.second != arr[j]) {
                    cout << prev.first << " " << prev.second << endl;
                    cout << arr[i] << " " << arr[j] << endl;
                    return 0;
                }
            } else {
                productMap[prod] = {arr[i], arr[j]};
            }
        }
    }

    cout << "No such pairs found" << endl;
    return 0;
}
