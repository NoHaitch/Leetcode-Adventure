#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int len = s.size();
        int i = 0;
        long ans = 0;
        bool foundSign = false, sign = false;
        bool firstChar = true;

        while(i < len && s[i] == ' '){
            i++;
        }

        while(i < len && (isdigit(s[i]) || (firstChar && ((s[i] == '-' && !foundSign) || (s[i] == '+' && !foundSign))))){
            if(firstChar){
                firstChar = false;
            }
            
            if(s[i] == '-'){
                foundSign = true;
                sign = true;
                i++;
                continue;
            }

            if(s[i] == '+'){
                foundSign = true;
                i++;
                continue;
            }

            if(sign){
                ans += (s[i] - '0') * -1;
            } else{
                ans += s[i] - '0';
            }

            i++;

            if(i < len && isdigit(s[i])){
                ans *= 10;
            }

            if(ans > INT_MAX){
                return INT_MAX;
            }

            if(ans < INT_MIN){
                return INT_MIN;
            }
        }

        return ans;
    }
};