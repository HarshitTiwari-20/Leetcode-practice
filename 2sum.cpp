#include <vector>
#include <unordered_map>
#include <stdexcept>

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