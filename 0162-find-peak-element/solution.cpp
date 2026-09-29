class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int st = 0;
        int ed = nums.size() - 1;

        while (st < ed) {
            int mid = st + (ed - st) / 2;

            if (nums[mid] < nums[mid + 1]) {
                st = mid + 1;
            } else {
                ed = mid;
            }
        }

        return st; 
    }
};