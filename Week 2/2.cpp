#include <iostream>
#include <vector>
using namespace std;

bool findSequence(const vector<int>& arr, int n){
    for (int k = n - 1; k >= 2; --k){
        int i = 0, j = k - 1;

        while (i < j){
            int sum = arr[i] + arr[j];
            if (sum == arr[k]) {
                cout << i << ", " << j << ", " << k << endl;
                return true;
            } else if (sum < arr[k]){
                ++i;
            } else{
                --j;
            }
        }
    }
    return false;
}

int main(){
    int T;
    cin >> T;

    while (T--){
        int n;
        cin >> n;
        vector<int> arr(n);
        
        for (int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        if (!findSequence(arr, n)){
            cout << "No sequence found." << endl;
        }
    }

    return 0;
}
