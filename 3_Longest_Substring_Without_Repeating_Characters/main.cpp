#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /* Brute Force */
    int lengthOfLongestSubstring1(string s) {
        int n = s.length();
        int max = 0;
        for(int i = 0; i < n; i++){
            int j = i;
            string subset = "";
            while(subset.find(s[j]) == string::npos && j < n){
                subset.push_back(s[j]);
                ++j;
            }
            int len = subset.length();
            if(len > max){
                max = len;
            }
        }
        return max;
    }

    /* Sliding Window Algorithm */
    int lengthOfLongestSubstring(string s) {
        vector<int> subStr(128, -1);
        int n = s.length();
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            if (subStr[s[right]] >= left) {
                left = subStr[s[right]] + 1;
            }
            subStr[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};