#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> H(1e4+1, 0);
        H[0] = 1;
        for (auto &v: nums) {
            H[v]++;
        }
        int d = max_element(H.begin(), H.end()) - H.begin();
        int m = min_element(H.begin()+1, H.end()) - H.begin();
        return {d, m};
    }
};