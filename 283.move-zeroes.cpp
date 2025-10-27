class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;  // Pointer for position of next non-zero element
        
        // Move all non-zero elements to the front
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};
