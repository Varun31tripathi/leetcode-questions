class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> indexMap;
        vector<string> result;
        int minSum = INT_MAX;
        
        // Step 1: Map strings from list1 to their indices
        for (int i = 0; i < list1.size(); i++) {
            indexMap[list1[i]] = i;
        }

        // Step 2: Check list2 for common strings
        for (int j = 0; j < list2.size(); j++) {
            if (indexMap.count(list2[j])) {
                int sum = j + indexMap[list2[j]];
                if (sum < minSum) {
                    result = {list2[j]};
                    minSum = sum;
                } else if (sum == minSum) {
                    result.push_back(list2[j]);
                }
            }
        }
        return result;
    }
};
