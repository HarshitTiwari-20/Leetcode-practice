// merge two_array.cpp --- 88

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> mergeTwoArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        merged.reserve(nums1.size() + nums2.size());
        
        // Merge the two arrays
        merged.insert(merged.end(), nums1.begin(), nums1.end());
        merged.insert(merged.end(), nums2.begin(), nums2.end());
        
        // Sort the merged array
        sort(merged.begin(), merged.end());
        
        return merged;
    }
};

//============================================================================================================================

// leetcode sol

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m-1;
        int p2 = n-1;
        int p = m+n-1;        
        while(p2 >= 0 && p1 >= 0){
            if (nums1[p1] > nums2[p2]){
                nums1[p] = nums1[p1];
                p1--;
            }
            else{
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }
        while(p2 >= 0){
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};