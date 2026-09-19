class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = nums.size();
        int l = 0;
        int r = s - 1;
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            
            if ((m - 1 < 0 || nums[m - 1] != nums[m]) && (m + 1 == s || nums[m] != nums[m + 1])) {
                return nums[m];
            }

            int leftSize = 0;
            if (nums[m] == nums[m - 1]) {
                leftSize = m - 1; 
            } else {
                leftSize = m;    
            }
            
           
            if (leftSize % 2 == 0) {
                l = m + 1;
            } 
           
            else {
                r = m - 1;
            }
        }
        
        return -1; 
    }
};