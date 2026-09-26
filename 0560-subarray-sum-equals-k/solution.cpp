class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCounts;
        prefixCounts[0] = 1; 
        
        int current_sum = 0;
        int cnt = 0;
        
        for (int num : nums) {
            current_sum += num;
            if (prefixCounts.find(current_sum - k) != prefixCounts.end()) {
                cnt += prefixCounts[current_sum - k];
            }
            prefixCounts[current_sum]++;
        }
        
        return cnt;
    }
};