#include<bits/stdc++.h>

vector<vector<int>> fourSum(Vector<int>& nums, int target) {
	
	int n = nums.size();
	set<vector<int>> st;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			set<long long> hashset;
			for(int k=j+1; k<n; k++){
				long long sum = nums[i] + nums[j];
				sum += nums[k];
				long long forth = target - (sum);
				if(hashset.find(forth) != hashset.end()){
					vetor<int> temp = {nums[i], nums[j], (int)froth};
					sort(temp.being(), temp.end());
					sort(temp.being(), temp.end());
					
				}
				hashset.insert(nums[k]);
				
			}
		}
	}
	vector<vector<int>> ans(st.being(), st.end());
	return ans;
}


-------------------------------------------------------------------------------------------------------
                  |
>> Optimizes Ans  | 
                  |
--------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
	    vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
	    for(int i = 0; i < n; i++){
		if(i>0 && nums[i] == nums[i-1]) continue;
		for(int j = i+1; j<n; j++){
			if(j != i+1 &&  nums[j] == nums[j-1]) continue;
			int k = j + 1;
			int l = n - 1;
			while(k < l){
				long long sum = nums[i];
				sum += nums[j];
				sum += nums[k];
				sum += nums[l];
				if(sum == target) {
					vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
					ans.push_back(temp);
					k++;
					l--;
					while(k < l && nums[k] == nums[k-1]) k++;
					while(k < l && nums[l] == nums[l-1]) l--;
					
					
				}
				else if(sum < target) k++;
				else l--;
			}
				
			
		}
	}
	return ans;
    }
};


========================================================================================

Gemini code

=========================================================================================

#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return {}; // A 4-sum is not possible if there are fewer than 4 elements.

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            // OPTIMIZATION 1: Check if the smallest possible sum from this point is too large.
            // If nums[i] + three smallest remaining numbers > target, we can stop.
            if ((long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) {
                break;
            }

            // OPTIMIZATION 2: Check if the largest possible sum with this 'i' is too small.
            // If nums[i] + three largest numbers < target, this nums[i] is too small.
            if ((long long)nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) {
                continue;
            }

            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i-1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                // OPTIMIZATION 3: Check smallest possible sum with 'i' and 'j'.
                if ((long long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) {
                    break;
                }

                // OPTIMIZATION 4: Check largest possible sum with 'i' and 'j'.
                if ((long long)nums[i] + nums[j] + nums[n-1] + nums[n-2] < target) {
                    continue;
                }
                
                // Skip duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j-1]) continue;

                // OPTIMIZATION 5: Pre-calculate the target for the two-pointer sum.
                long long remaining_target = (long long)target - nums[i] - nums[j];
                int k = j + 1;
                int l = n - 1;

                while (k < l) {
                    long long two_sum = nums[k] + nums[l];

                    if (two_sum == remaining_target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        
                        // Skip duplicates for the third and fourth elements
                        while (k < l && nums[k] == nums[k-1]) k++;
                        // BUG FIX: Compare nums[l] with its previous position (l+1)
                        while (k < l && nums[l] == nums[l+1]) l--;
                    }
                    else if (two_sum < remaining_target) {
                        k++;
                    }
                    else { // two_sum > remaining_target
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};
