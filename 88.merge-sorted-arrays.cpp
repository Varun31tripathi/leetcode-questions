#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;       // last valid index in nums1
        int j = n - 1;       // last index in nums2
        int k = m + n - 1;   // last index of merged array
        
        // merge from the end
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }

        // if nums2 still has elements, copy them
        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};
