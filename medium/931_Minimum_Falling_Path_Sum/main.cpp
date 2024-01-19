#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {       
        int n = matrix.size(); 

        vector<vector<int>> dp(n, vector<int>(n, 0)); 
        
        for(int j = 0; j < n; j++){
            dp[0][j] = matrix[0][j];     
        }
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int left = 1e9, right = 1e9;
                int mid = matrix[i][j] + dp[i-1][j]; 
    
                if(j-1 >= 0)
                    left = matrix[i][j] + dp[i-1][j-1]; 
                if(j+1 < n)
                    right = matrix[i][j] + dp[i-1][j+1]; 
                
                dp[i][j]  =  min(mid, min(left,right));    
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
}; 