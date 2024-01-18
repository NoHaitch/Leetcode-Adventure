#include <stdint.h>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        while(n > 0){
            if(n & 0x1){
                count++;
            }

            n = n >> 1;
        }

        return count;
    }
};