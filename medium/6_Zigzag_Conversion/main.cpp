#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();

        if(len <= numRows || numRows == 1){
            return s;
        }
        
        vector<string> strRow (numRows,"");

        int i = 0, j;
        while(i < len){
            for(j = 0; j < numRows && i < len; j++){
                strRow[j] += s[i];
                i++;
            }

            for(j = numRows - 2; j > 0 && i < len; --j){
                strRow[j] += s[i];
                i++;
            }
        }

        string res = "";

        for(int i = 0; i < numRows; i++){
            res += strRow[i];
        }

        return res;
    }
};