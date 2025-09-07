#include <bits/std++.h>


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int element1 = 0, element2 = 0, count1 = 0, count2 = 0;
        for (int it : nums) {
            if (it == element1)
                count1++;
            else if (it == element2)
                count2++;
            else if (!count1) {
                element1 = it;
                count1++;
            }
            else if (!count2) {
                element2 = it;
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;
        for (auto it : nums) {
            if (element1 == it)
                count1++;
            else if (it == element2)
                count2++;
        }

        vector<int> ans;
        if (count1 > (n / 3))
            ans.push_back(element1);
        if (count2 > (n / 3))
            ans.push_back(element2);

        return ans;
    }
};