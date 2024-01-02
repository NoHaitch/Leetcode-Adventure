#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--){
            if(carry){
                digits[i] ++;
                if(digits[i] == 10){
                    digits[i] = 0;
                } else {
                    carry = 0;
                }
            } else{
                return digits;
            }
        }
        if(carry){
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};