#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int len = s.length();
        for(int i = 0; i < (int)len/2; i++){
            int j = len - i - 1;
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
};