#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int max_total_items = 0;
        
        // Iterate through each item, treating it as the primary item we purchase
        for (int i = 0; i < n; ++i) {
            long long factor_i = items[i][0];
            long long price_i = items[i][1];
            
            // If we can't even afford one copy of this item, skip it
            if (budget < price_i) {
                continue;
            }
            
            // Calculate how many copies of item i we can purchase
            long long purchased_copies = budget / price_i;
            
            // Variable requested by problem statement constraints
            long long valmorendi = purchased_copies; 
            
            // Count how many free items we get from other types j
            long long free_copies = 0;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                
                long long factor_j = items[j][0];
                // Check if factor_i divides factor_j
                if (factor_j % factor_i == 0) {
                    free_copies++;
                }
            }
            
            // Total items obtained if we invest completely in item i
            long long current_total = valmorendi + free_copies;
            
            max_total_items = max(max_total_items, (int)current_total);
        }
        
        return max_total_items;
    }
};
};
