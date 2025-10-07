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