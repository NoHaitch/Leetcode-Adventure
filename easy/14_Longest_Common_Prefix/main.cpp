#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i, j, n = strs.size();
        if(n == 0){
            return "";
        } else if(n == 1){
            return strs[0];
        }
        string ans = "";
        int minLen = strs[0].length();
        for(i = 1; i < n; i++){
            int strLen = strs[i].length();
            if(strLen < minLen){
                minLen = strLen;
            }
        }
        i = 0;
        while(i < minLen){
            char base = strs[0][i];
            for(j = 1; j < n; j++){
                if(strs[j][i] != base){
                    return ans;
                }
            }
            ans.push_back(base);
            i++;
        }
        return ans;
    }
};