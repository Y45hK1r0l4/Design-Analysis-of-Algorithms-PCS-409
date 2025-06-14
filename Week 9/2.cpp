
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(vector<int>& a, vector<int>& b){
    double a1 = (1.0 * a[0]) / a[1];
    double b1 = (1.0 * b[0]) / b[1];
    return a1 > b1;
}

double fractionalKnapSack(vector<int>& val, vector<int>& wt, int capacity){
    int n = val.size();

    vector<vector<int>> items(n, vector<int> (3));

    for(int i = 0; i < n; i++){
        items[i][0] = val[i];
        items[i][1] = wt[i];
        items[i][2] = i + 1;
    }

    sort(items.begin(), items.end(), compare);

    double res = 0.0;
    int currentCapacity = capacity;
    vector<pair<int, double>> selected;

    for (int i = 0; i < n; i++) {
        if (items[i][1] <= currentCapacity) {
            // Take the whole item
            res += items[i][0];
            currentCapacity -= items[i][1];
            selected.push_back({items[i][2], (double)items[i][1]});
        } else {
            // Take a fraction
            double fraction = (double)currentCapacity / items[i][1];
            if (fraction > 0.0) {
                res += items[i][0] * fraction;
                selected.push_back({items[i][2], items[i][1] * fraction});
            }
            break;
        }
    }

    cout << "Maximum value : " << res << endl;
    cout << "item-weight" << endl;
    for (auto& it : selected) {
        cout << it.first << "-" << it.second << endl;
    }

    return res;
    return res;
}

int main(){
    vector<int> val;
    vector<int> wt;

    int n;

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter values: ";
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        val.push_back(v);
    }

    cout << "Enter weights: ";
    for(int i = 0; i < n; i++){
        int w;
        cin >> w;
        wt.push_back(w);
    }

    int capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    fractionalKnapSack(val, wt, capacity);

    return 0;
}
