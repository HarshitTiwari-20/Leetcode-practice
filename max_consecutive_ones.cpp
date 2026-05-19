class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int crt = 0;
        int result = 0;
        for(int i = 0; i < n; i++){
            if(nums[i]==1){
                crt++;
                result = max(result,crt);
                
            }
            else {
                crt = 0;
            }
        }
        return result;
    }
};



