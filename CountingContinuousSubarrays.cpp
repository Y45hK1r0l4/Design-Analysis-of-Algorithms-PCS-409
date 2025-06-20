#include <iostream>
#include <vector>
using namespace std;

int countIncreasingSubarrays(const vector<int>& arr) {
    int n = arr.size();
    int count = 0, length = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1])
            length++;
        else {
            count += (length * (length + 1)) / 2;
            length = 1;
        }
    }

    count += (length * (length + 1)) / 2;  // last segment
    return count;
}

int main() {
    vector<int> arr = {1, 2, 3, 2, 4};
    cout << "Total strictly increasing subarrays: " << countIncreasingSubarrays(arr) << endl;
    return 0;
}





int countSubarraysWithSumLessThanK(vector<int>& nums, int k) {
    int count = 0;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += nums[j];
            if (sum < k)
                count++;
            else
                break; // no need to go further
        }
    }

    return count;
}





int countSubarraysWithSumEqualToK(vector<int>& nums, int k) {
    int count = 0;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += nums[j];
            if (sum == k)
                count++;
        }
    }

    return count;
}






#include <iostream>
#include <vector>
using namespace std;

void countEvenOddSubarrays(vector<int>& nums) {
    int evenCount = 0, oddCount = 0;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += nums[j];
            if (sum % 2 == 0)
                evenCount++;
            else
                oddCount++;
        }
    }

    cout << "Subarrays with even sum: " << evenCount << endl;
    cout << "Subarrays with odd sum: " << oddCount << endl;
}

int main() {
    vector<int> nums = {1, 2, 3};
    countEvenOddSubarrays(nums);
    return 0;
}





int countValidSubarrays(const vector<int>& arr, int K) {
    int N = arr.size();
    int count = 0;

    // i is the starting index of the subarray
    for (int i = 0; i < N; ++i) {
        unordered_map<int, int> freq;

        // j is the ending index of the subarray
        for (int j = i; j < N; ++j) {
            freq[arr[j]]++;  // Update frequency of arr[j]

            // Check if all elements in current subarray appear at least K times
            bool valid = true;
            for (const auto& p : freq) {
                if (p.second < K) {
                    valid = false;
                    break;
                }
            }

            // If all frequencies >= K, count this subarray
            if (valid)
                count++;
        }
    }

    return count;
}





