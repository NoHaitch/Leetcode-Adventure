#include <vector>
#include <stack>

using namespace std;
const int MOD = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int len = nums.size();
        vector<int> left(len, -1);
        vector<int> right(len, len);
        stack<int> s;

        for (int i = 0; i < len; ++i) {
            while (!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }

            if (!s.empty()) {
                left[i] = s.top();
            }
            s.push(i);
        }

        s = stack<int>();

        for (int i = len - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                s.pop();
            }

            if (!s.empty()) {
                right[i] = s.top();
            }
            s.push(i);
        }

        long long sum = 0;

        for (int i = 0; i < len; ++i) {
            sum += static_cast<long long>(i - left[i]) * (right[i] - i) * nums[i] % MOD;
            sum %= MOD;
        }

        return sum;
    }
};