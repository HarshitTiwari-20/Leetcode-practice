// leetcode 287

// direct code

int slow = nums[0];
int fast = nums[0];
do {
slow = nums[slow];
fast = nums[nums[fast]];

}

while (slow != fast);

fast = nums[0];
while(slow != fast){
slow = nums[slow];
fast = nums[fast];
}

return slow;







/*==================================================================================================================================*/


#include <vector>
#include <unordered_set>
using namespace std;    
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) {
                return num; // Duplicate found
            }
            seen.insert(num);
        }
        return -1; // No duplicate found (should not happen as per problem constraints)
    }
};


//============================================================================================================================


// Floyd's Tortoise and Hare (Cycle Detection) Algorithm    
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0];
        int hare = nums[0];
        
        // Phase 1: Finding the intersection point in the cycle
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);
        
        // Phase 2: Finding the entrance to the cycle
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        return hare;
    }
};  

//============================================================================================================================
// Binary Search Approach
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for (int num : nums) {
                if (num <= mid) {
                    count++;
                }
            }
            if (count > mid) {
                right = mid; // The duplicate is in the range [left, mid]
            } else {
                left = mid + 1; // The duplicate is in the range [mid + 1, right]
            }
        }
        return left; // or right, since left == right
    }   
};
//============================================================================================================================
// Sorting Approach
#include <vector>   
#include <algorithm>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i]; // Duplicate found
            }
        }
        return -1; // No duplicate found (should not happen as per problem constraints)
    }
};
//============================================================================================================================
// Negative Marking Approach
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1; // Get the index corresponding to the value
            if (nums[index] < 0) {
                return abs(nums[i]); // Duplicate found
            }
            nums[index] = -nums[index]; // Mark the number as seen by negating the value at that index
        }
        return -1; // No duplicate found (should not happen as per problem constraints)
    }
};
//============================================================================================================================
// Brute Force Approach (Not Recommended for Large Inputs)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    return nums[i]; // Duplicate found
                }
            }
        }
        return -1; // No duplicate found (should not happen as per problem constraints)
    }
};
//============================================================================================================================  
// Using a Frequency Array (Not Space Efficient)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n, 0);
        for (int num : nums) {
            freq[num]++;
            if (freq[num] > 1) {
                return num; // Duplicate found
            }
        }
        return -1; // No duplicate found (should not happen as per problem constraints)
    }
};
//============================================================================================================================
// Using a Hash Map (Similar to Set Approach)   
#include <unordered_map>
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
            if (countMap[num] > 1) {
                return num; // Duplicate found
            }
        }
        return -1; // No duplicate found (should not happen as per problem constraints)
    }
};
//============================================================================================================================
// Using std::find (Less Efficient)
#include <algorithm>
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (std::find(nums.begin() + i + 1, nums.end(), nums[i]) != nums.end()) {
                return nums[i]; // Duplicate found
            }
        }
        return -1; // No duplicate found (should not happen as per problem constraints)
    }   
};
//============================================================================================================================
// Using std::sort and std::adjacent_find   
#include <algorithm>
class Solution {
public:
    int findDuplicate(vector<int>& nums)    {
        std::sort(nums.begin(), nums.end());
        auto it = std::adjacent_find(nums.begin(), nums.end());
        if (it != nums.end()) {
            return *it; // Duplicate found
        }
        return -1; // No duplicate found (should not happen as per problem constraints)
    }
};
//============================================================================================================================
// Using std::unordered_multiset
#include <unordered_set>
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       
         std::unordered_multiset<int> numSet;
        for (int num : nums) {
            auto result = numSet.insert(num);
            if (!result.second) {
                return num; // Duplicate found
            }
        }
        return -1; // No duplicate found (should not happen as per problem constraints) 
    }
};  
//============================================================================================================================
