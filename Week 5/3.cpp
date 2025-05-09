#include <iostream>
#include <vector>
using namespace std;

void findCommonElements(vector<int>& arr1, vector<int>& arr2){
    int i = 0, j = 0;
    bool found = false;

    while (i < arr1.size() && j < arr2.size()){
        if (arr1[i] == arr2[j]){
            cout << arr1[i] << " ";
            found = true;
            i++;
            j++;
        } else if (arr1[i] < arr2[j]){
            i++;
        } else{
            j++;
        }
    }

    if (!found){
        cout << "No common elements found." << endl;
    } else{
        cout << endl;
    }
}

int main(){
    int m, n;
    
    cout << "Enter size of first array: ";
    cin >> m;
    vector<int> arr1(m);
    cout << "Enter elements of first array (sorted): ";
    for (int i = 0; i < m; i++){
        cin >> arr1[i];
    }

    cout << "Enter size of second array: ";
    cin >> n;
    vector<int> arr2(n);
    cout << "Enter elements of second array (sorted): ";
    for (int i = 0; i < n; i++){
        cin >> arr2[i];
    }

    cout << "Common elements: ";
    findCommonElements(arr1, arr2);

    return 0;
}
