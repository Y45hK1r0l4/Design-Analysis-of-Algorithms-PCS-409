
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMajorityElement(const vector<int>& arr, int n){
    int count = 0, candidate = -1;

    for(int num : arr){
        if(count == 0){
            candidate = num;
            count = 1;
        }else if(num == candidate){
            count++;
        }else{
            count--;
        }
    }

    count = 0;
    for(int num : arr){
        if(num == candidate) count++;
    }

    return(count > n/2) ? candidate : -1;
}

double  findMedian(vector<int>& arr, int n){
    sort(arr.begin(), arr.end());
    if (n % 2 == 1) return arr[n / 2];
    return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    int majority = findMajorityElement(arr, n);
    if (majority != -1)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    cout << findMedian(arr, n) << endl;

    return 0;
}
