#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Use pointers to avoid expensive deep copies of the vectors
        vector<int>* A = &nums1;
        vector<int>* B = &nums2;
        
        if (B->size() < A->size()) {
            swap(A, B);
        }
        
        int total = A->size() + B->size();
        int half = total / 2;
        
        int l = 0;
        int r = A->size() - 1;
        
        while (true) {
            int sum = l + r;
            int i = (sum < 0) ? (sum - 1) / 2 : sum / 2;
            int j = half - i - 2;
            
            int Aleft = (i >= 0) ? (*A)[i] : INT_MIN;
            int Aright = (i + 1 < A->size()) ? (*A)[i + 1] : INT_MAX;
            int Bleft = (j >= 0) ? (*B)[j] : INT_MIN;
            int Bright = (j + 1 < B->size()) ? (*B)[j + 1] : INT_MAX;
            
            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 != 0) {
                    return min(Aright, Bright);
                } else {
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
                }
            }
            else if (Aleft > Bright) {
                r = i - 1;
            } 
            else {
                l = i + 1;
            }
        }
    }
};