#include <iostream>
#include <algorithm> 
using namespace std;

bool hasDuplicates(int arr[], int n){
    sort(arr, arr + n);

    for (int i = 0; i < n - 1; i++){
        if (arr[i] == arr[i + 1]){
            return true;
        }
    }
    return false;
}

int main(){
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;

    while (T--){
        int n;
        cout << "Enter array size: ";
        cin >> n;

        int arr[n];
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }

        if (hasDuplicates(arr, n)){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
