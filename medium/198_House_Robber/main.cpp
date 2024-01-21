#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> robbed(2, 0);
        vector<int> notRobbed(2, 0);
        notRobbed[0] = nums[0];

        for (int i = 1; i < n; i++) {
            robbed[i % 2] = max(robbed[(i - 1) % 2], notRobbed[(i - 1) % 2]);
            notRobbed[i % 2] = robbed[(i - 1) % 2] + nums[i];
        }

        return max(robbed[(n - 1) % 2], notRobbed[(n - 1) % 2]);
    }
};