#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        
        if(numRows > 0){
            ans[0] = {1};
        }

        if(numRows > 1){
            ans[1] = {1,1};
        }

        for(int i = 2; i < numRows; i++){
            vector<int> currRow(i+1, 1);
    
            for(int j = 1; j < i; j++){
                currRow[j] = ans[i-1][j-1] + ans[i-1][j];
            }

            ans[i] = currRow;
        }
       
        return ans;
    }
};