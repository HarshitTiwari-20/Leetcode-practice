class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
         int rows = (int)mat.size();
        int cols = (int)mat[0].size();
        int low = 0;
        int high = rows - 1;
 
        while (low < high) {
           
            int mid = low + (high - low) / 2;
 
            
            int bestCol = 0;
            for (int col = 1; col < cols; col++) {
               
                if (mat[mid][col] > mat[mid][bestCol]) {
                    bestCol = col;
                }
            }
 
          
            if (mat[mid][bestCol] > mat[mid + 1][bestCol]) {
                high = mid;
            } else {
               
                low = mid + 1;
            }
        }
 
        
        int bestCol = 0;
        for (int col = 1; col < cols; col++) {
           
            if (mat[low][col] > mat[low][bestCol]) {
                bestCol = col;
            }
        }
 
        return {low, bestCol};
    }
};