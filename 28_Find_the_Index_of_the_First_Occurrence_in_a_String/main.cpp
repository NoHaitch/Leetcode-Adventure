#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0; i < haystack.size(); i++){
            if(haystack[i] == needle[0]){
                bool check = 1;
                for(int j = 1; j < needle.size(); j++){
                    if(haystack[i+j] != needle[j]){
                        check = 0;
                        break;
                    }
                } 
                if(check){
                    return i;
                }
            }
        }
        return -1;
    }
};