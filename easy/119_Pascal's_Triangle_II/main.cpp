#include <vector>

using namespace std;

class Solution {
public:
    // high speed, high space
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(rowIndex+1);
        
        if(rowIndex >= 0){
            ans[0] = {1};
        }

        if(rowIndex >= 1){
            ans[1] = {1,1};
        }

        for(int i = 2; i <= rowIndex; i++){
            vector<int> currRow(i+1, 1);
    
            for(int j = 1; j < i; j++){
                currRow[j] = ans[i-1][j-1] + ans[i-1][j];
            }

            ans[i] = currRow;
        }
       
        return ans[rowIndex];
    }

    // low speed, low space
    vector<int> getRow2(int rowIndex) {
        vector<vector<int>> ans(rowIndex+1);
        
        if(rowIndex >= 0){
            ans[0] = {1};
        }

        if(rowIndex >= 1){
            ans[1] = {1,1};
        }

        for(int i = 2; i <= rowIndex; i++){
            vector<int> currRow(i+1, 1);
    
            for(int j = 1; j < i; j++){
                currRow[j] = ans[i-1][j-1] + ans[i-1][j];
            }

            ans[i] = currRow;
        }
    
        return ans[rowIndex];
    }
};