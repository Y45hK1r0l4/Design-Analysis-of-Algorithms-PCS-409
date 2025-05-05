#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(const vector<int>& arr, int key){
    int low = 0, high = arr.size() - 1, result = -1;

    while (low <= high){
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            result = mid;
            high = mid - 1;  
        } else if (arr[mid] > key){
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }
    return result;
}

int lastOccurrence(const vector<int>& arr, int key){
    int low = 0, high = arr.size() - 1, result = -1;

    while (low <= high){
        int mid = low + (high - low) / 2;
        if (arr[mid] == key){
            result = mid;
            low = mid + 1;  
        } else if (arr[mid] > key){
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }
    return result;
}

int main(){
    int T;
    cin >> T;

    while (T--){
        int n, key;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        cin >> key;

        int first = firstOccurrence(arr, key);
        int last = lastOccurrence(arr, key);

        if (first == -1){
            cout << "Key not present" << endl;
        } else{
            cout << key << " - " << (last - first + 1) << endl;
        }
    }

    return 0;
}
