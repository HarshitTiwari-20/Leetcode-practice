class Solution {
private:
    void backtrack(vector<int>& nums, int first, vector<vector<int>>& results) {
        if (first == nums.size() - 1) {
            results.push_back(nums);
            return;
        }

        for (size_t i = first; i < nums.size(); ++i) {
            // 1. CHOOSE
            swap(nums[first], nums[i]);

            // 2. EXPLORE
            backtrack(nums, first + 1, results);

            // 3. UN-CHOOSE
            swap(nums[first], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        if (nums.empty()) return results;

        backtrack(nums, 0, results);
        return results;
    }
};