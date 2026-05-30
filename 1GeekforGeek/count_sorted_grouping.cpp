#include <iostream>
#include <string>
#include <vector>
#include <cstring>

class Solution {
private:
    int dp[41][370]; // Adjusted sizes based on typical constraints (length <= 40, max_sum <= 360)

    int countGroupings(int index, int prev_sum, const std::string& s) {
        // Base case: successfully partitioned the entire string
        if (index == s.length()) {
            return 1;
        }

        // Return cached result if already calculated
        if (dp[index][prev_sum] != -1) {
            return dp[index][prev_sum];
        }

        int current_sum = 0;
        int total_ways = 0;

        // Try creating all possible sub-groups starting from 'index'
        for (int i = index; i < s.length(); ++i) {
            current_sum += (s[i] - '0'); // Add digit to the current sub-group sum

            // Condition for a non-decreasing sequence
            if (current_sum >= prev_sum) {
                total_ways += countGroupings(i + 1, current_sum, s);
            }
        }

        return dp[index][prev_sum] = total_ways;
    }

public:
    int TotalCount(std::string s) {
        // Initialize DP table with -1
        std::memset(dp, -1, sizeof(dp));
        
        // Start from index 0 with an initial previous sum of 0
        return countGroupings(0, 0, s);
    }
};


//-----------------------------------------------------------------------------------------------------

#include <string>
#include <vector>
#include <numeric>
#include <cstring>

using namespace std;

class Solution {
  private:
    // dp[index][prev_sum]
    // Max length of string is typically around 40, so max possible sum is ~360
    int dp[41][370]; 

    int solve(int index, int prev_sum, const vector<int>& a) {
        // Base case: If we've processed the entire string, we found 1 valid grouping
        if (index == a.size()) {
            return 1;
        }

        // Return the cached result if it exists
        if (dp[index][prev_sum] != -1) {
            return dp[index][prev_sum];
        }

        int current_sum = 0;
        int total_ways = 0;

        // Form all possible sub-groups starting from 'index' to 'i'
        for (int i = index; i < a.size(); ++i) {
            current_sum += a[i];

            // If the current sub-group sum maintains the non-decreasing order
            if (current_sum >= prev_sum) {
                total_ways += solve(i + 1, current_sum, a);
            }
        }

        // Memoize and return
        return dp[index][prev_sum] = total_ways;
    }

  public:
    int validGroups(string &s) {
        vector<int> a;
        
        // Convert the string characters into an integer array of digits
        for (char ch : s) {
            a.push_back(ch - '0');
        }

        // Initialize the DP table with -1
        memset(dp, -1, sizeof(dp));

        // Start recursion from index 0 with an initial previous sum of 0
        return solve(0, 0, a);
    }
};
