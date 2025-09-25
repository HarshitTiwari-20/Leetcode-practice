#include <vector> // Include vector header
#include <iostream>

class Solution {
public:
    int merge(std::vector<int> &arr, int low, int mid, int high) {
        std::vector<int> temp;
        int left = low;
        int right = mid + 1;
        int count = 0;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                count += (mid - left + 1); // Count inversions
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return count;
    }

    int mergesort(std::vector<int> &arr, int low, int high) {
        int count = 0;
        if (low >= high) return count;
        int mid = low + (high - low) / 2; // Safer midpoint calculation
        count += mergesort(arr, low, mid);
        count += mergesort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);
        return count;
    }

    int numberOfInversions(std::vector<int>& a, int n) {
        if (n <= 0) return 0; // Handle empty or invalid input
        return mergesort(a, 0, n - 1);
    }
};

int main() {
    std::vector<int> arr = {5, 3, 2, 4, 1};
    int n = arr.size();
    Solution sol;
    int inversions = sol.numberOfInversions(arr, n); // Correct call
    std::cout << "Number of inversions: " << inversions << std::endl;
    return 0;
}