#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, k = 1;

        for(i = 1; i < nums.size(); i++){
            if(nums[i] != nums[k-1]){
                nums[k] = nums[i];
                k++;
            }
        }
        
        return k;
    }
};