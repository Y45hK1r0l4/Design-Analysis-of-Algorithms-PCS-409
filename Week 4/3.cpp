#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int j = low - 1;

    for(int i = low; i < high; i++) {
        if(arr[i] < pivot) {
            swap(arr[++j], arr[i]);
        }
    }
    swap(arr[j + 1], arr[high]);
    return j + 1;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);

        if (pi == k - 1)  
            return arr[pi];
        else if (pi > k - 1)
            return quickSelect(arr, low, pi - 1, k);  
        else
            return quickSelect(arr, pi + 1, high, k);
    }
    return -1;  
}

int main() {
    int T;
    cin >> T;  

    while (T--) {
        int n;
        cin >> n; 
        int arr[n];

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int k;
        cin >> k;  

        if (k > 0 && k <= n) {
            cout << quickSelect(arr, 0, n - 1, k) << endl;
        } else {
            cout << "not present" << endl;
        }
    }

    return 0;
}
