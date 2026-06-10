class Solution {
public:
    // Helper function to handle the backtracking recursion
    void findCombinations(int index, int currentTarget, vector<int>& candidates, vector<vector<int>>& result, vector<int>& currentCombination) {
        // Base case: If we reach the end of the array
        if (index == candidates.size()) {
            // If the target is exactly 0, we found a valid combination
            if (currentTarget == 0) {
                result.push_back(currentCombination);
            }
            return;
        }

        // Option 1: Pick the current number
        // We only pick it if it doesn't exceed our current target
        if (candidates[index] <= currentTarget) {
            currentCombination.push_back(candidates[index]);
            
            // Notice we pass 'index' (not index + 1) because we can reuse the same element
            findCombinations(index, currentTarget - candidates[index], candidates, result, currentCombination);
            
            // Backtrack: Remove the number we just added so we can try the next option
            currentCombination.pop_back(); 
        }

        // Option 2: Skip the current number and move to the next one
        findCombinations(index + 1, currentTarget, candidates, result, currentCombination);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        
  
// Start the recursive search from index 0
        findCombinations(0, target, candidates, result, currentCombination);
        
        return result;
    }
};


//------------------------------------------------------------------------------------------------ 


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> ans;
      vector<int> ds;
      findCombination(0, target, candidates, ans, ds);
      return ans;
        
    }

public:
    void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>> &ans, vector<int> &ds){
      if( ind == arr.size()){
        if(target == 0){
          ans.push_back(ds);
        }
        return;
      }
      if(arr[ind] <= target){
        ds.push_back(arr[ind]);
        findCombination(ind, target - arr[ind], arr, ans, ds;
        ds.pop_back();
      }
      findCombination(ind+1, target,arr,ans,ds);

    }
};