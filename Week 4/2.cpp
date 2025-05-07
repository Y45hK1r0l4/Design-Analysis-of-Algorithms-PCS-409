#include <iostream>
using namespace std;

int comparisons = 0; 
int swaps = 0;      

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
    swaps++; 
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    
    for(int j = low; j < high; j++){
        comparisons++;
        if(arr[j] < pivot){
            i++;
            swap(arr[i] , arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;

}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nNumber of comparisons: " << comparisons;
    cout << "\nNumber of swaps: " << swaps << endl;

    return 0;
}
