#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>

// This function is unchanged. Its logic is still correct.
std::vector<int> twoSumHashing(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (map.count(complement)) {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    throw std::invalid_argument("No two sum solution");
}

// The main function is updated to take input from the user.
int main() {
    try {
        int n;
        std::cout << "Enter the number of elements in the array: ";
        std::cin >> n;

        std::vector<int> numbers;
        std::cout << "Enter " << n << " numbers separated by spaces: ";
        for (int i = 0; i < n; ++i) {
            int element;
            std::cin >> element;
            numbers.push_back(element);
        }

        int target;
        std::cout << "Enter the target sum: ";
        std::cin >> target;
        
        // Call the function with the user-provided data
        std::vector<int> result = twoSumHashing(numbers, target);
        
        // Print the result
        std::cout << "Success! Indices found: [" << result[0] << ", " << result[1] << "]" << std::endl;

    } catch (const std::invalid_argument& e) {
        // Catch the error if no solution is found
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}