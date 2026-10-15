class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = nums.size();
        if( s == 0 && target == nums[0]) return true;
        for( int i = 0; i < s ; i++){
            if( nums[i] == target) {
                return true;
            }
            
        }
        return false;
    }
};