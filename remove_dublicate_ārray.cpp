class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        for(int i = 0; i < n -1 ; i++){
            if(nums[i] != nums[i+1]){
                result.push_back(nums[i]);
            }
        }
        result.push_back(nums[n-1]);
        nums = result;
        //nums.assign(result.begin(), result.end());
        return nums.size();
        
    }
};

//--------------------------------------------------------------------


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it = std::unique(nums.begin(), nums.end());
        return std::distance(nums.begin(), it);
        
    }
};

//-------------------------------------------------------------------------

class Solution {
public:
    // Function to remove duplicates from sorted array in-place
    int removeDuplicates(vector<int>& nums) {
        // If array is empty, return 0 directly
        if (nums.empty()) return 0;

        // Pointer for the position of last unique element
        int i = 0;

        // Traverse the array starting from the second element
        for (int j = 1; j < nums.size(); j++) {
            // If current element is different from last unique element
            if (nums[j] != nums[i]) {
                // Move pointer for unique element forward
                i++;
                // Place the new unique element at the next position
                nums[i] = nums[j];
            }
        }

        // i is index of last unique element, count = i + 1
        return i + 1;
    }
};


//---------------------------------------------------------------------------------------------------
//
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 0;

        for (int j = 0; j<nums.size(); j++ ){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }

        return i+1;
        
    }
};


