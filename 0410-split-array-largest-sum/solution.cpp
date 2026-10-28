class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        
        auto cansplit = [&](int largest) {
            int subarrays = 1;
            int cursum = 0;
            for (int num : nums) {
                if (cursum + num > largest) {
                    subarrays++;
                    cursum = num;
                } else {
                    cursum += num;
                }
            }
            return subarrays <= k;
        };

       
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int res = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (cansplit(mid)) {
                res = mid;      
                r = mid - 1;
            } else {
                l = mid + 1;    
            }
        }
        
        return res;
    }
};