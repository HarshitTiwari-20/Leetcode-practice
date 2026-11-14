class Solution {
private:
    int countAtMost(vector<int>& nums, int goal) {
        int n = nums.size();

        if(goal < 0){
            return 0;
        }

        int cnt = 0;
        int left = 0;
        int crtsum = 0;
        

        for(int i = 0; i < n; i++){
            crtsum += nums[i];
            while ( crtsum > goal){
                crtsum -= nums[left];
                left++;
            }
            cnt += i - left + 1;
        }
        return cnt;
    }

public:
   
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countAtMost(nums, goal) - countAtMost(nums, goal - 1);
    }
};