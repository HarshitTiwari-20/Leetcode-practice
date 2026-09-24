// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         vector<int> heap;
//         int cnt  = 0;
//         for( int i = 0; i < nums.size(); i++){
//             if( nums[i] == 0){
//                 cnt++;
//                 nums.pop_back();
//             }
//         }
//         return nums + (cnt * 0)
//     }
// };


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                std::swap(nums[lastNonZeroFoundAt++], nums[i]);
            }
        }
    }
};