#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        for (int i = s.size() - 1; i >= 0; --i){
            if (s[i] != ' '){
                len ++;
            }
            if (len > 0 && s[i] == ' '){
                return len;
            }
        }
        return len;
    }
};