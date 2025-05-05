#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key, int &comparisons){
    int low = 0, high = n - 1;

    while (low <= high){
        comparisons++;
        int mid = (low + high) / 2;
        
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(){
    int testCases;
    cin >> testCases;

    while (testCases--){
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        int key;
        cin >> key;

        int comparisons = 0;
        int result = binarySearch(arr, n, key, comparisons);

        if (result != -1)
            cout << "Present " << comparisons << endl;
        else
            cout << "Not Present " << comparisons << endl;
    }
    return 0;
}

