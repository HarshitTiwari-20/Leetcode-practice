#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>

// The converted function from above
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

int main() {
    std::vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    try {
        std::vector<int> result = twoSumHashing(numbers, target);
        std::cout << "Indices found: [" << result[0] << ", " << result[1] << "]" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    // Example that will throw an exception
    std::vector<int> numbers2 = {3, 5, 8};
    int target2 = 10;

    try {
        std::vector<int> result2 = twoSumHashing(numbers2, target2);
        std::cout << "Indices found: [" << result2[0] << ", " << result2[1] << "]" << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error for second example: " << e.what() << std::endl;
    }

    return 0;
}
