#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size(), n = nums2.size();
        int totalLeft = (m + n + 1) / 2;

        int low = 0, high = m;
        while (low <= high) {
            int i = (low + high) / 2;        
            int j = totalLeft - i;            

            int leftA  = (i == 0) ? INT_MIN : nums1[i - 1];
            int rightA = (i == m) ? INT_MAX : nums1[i];
            int leftB  = (j == 0) ? INT_MIN : nums2[j - 1];
            int rightB = (j == n) ? INT_MAX : nums2[j];

            if (leftA <= rightB && leftB <= rightA) {
                
                if ((m + n) % 2 == 0)
                    return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
                else
                    return max(leftA, leftB);
            } else if (leftA > rightB) {
                high = i - 1; 
            } else {
                low = i + 1;
            }
        }
        return 0.0;
    }
};
