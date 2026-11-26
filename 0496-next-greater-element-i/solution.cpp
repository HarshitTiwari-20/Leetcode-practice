class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = static_cast<int>(nums2.size());
        unordered_map<int, int> nge;
        stack<int> can;

        for (int i = n - 1; i >= 0; --i) {
            while (!can.empty() && can.top() <= nums2[i]) {
                can.pop();
            }
            nge[nums2[i]] = can.empty() ? -1 : can.top();
            can.push(nums2[i]);
        }

        vector<int> ans;
        ans.reserve(nums1.size());
        for (int x : nums1) {
            ans.push_back(nge[x]);
        }

        return ans;
    }
};