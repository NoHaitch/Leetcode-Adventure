#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /* Way 1: Brute Forced, O(n^2) */
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     for(int i = 0; i < nums.size(); i++){
    //         for(int j = i + 1; j < nums.size(); j++){
    //             if(nums[i] + nums[j] == target){
    //                 return {i, j};
    //             }
    //         }
    //     }
    //     return {};
    // }

    /* Way 2: HasMap, O(n) */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];

            if (seen.count(diff)) {
                return {seen[diff], i};
            } else {
                seen[nums[i]] = i;
            }
        }

        return {};
    }
};