#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {
            return;
        }

        if (m == 0) {
            for (int i = 0; i < n; i++) {
                nums1[i] = nums2[i];
            }
            return;
        }

        int curr = m + n - 1;
        int idx1 = m - 1;
        int idx2 = n - 1;

        while (idx2 >= 0) {
            if (idx1 >= 0 && nums1[idx1] > nums2[idx2]) {
                nums1[curr--] = nums1[idx1--];
            } else {
                nums1[curr--] = nums2[idx2--];
            }
        }
    }
};