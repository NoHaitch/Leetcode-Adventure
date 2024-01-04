#include <unordered_map>

using namespace std;

class Solution {
public:
    // 1 Memoization Technique
    int climbStairs1(int n, unordered_map<int, int>& cache) {
        if (n == 0 || n == 1) {
            return 1;
        }
        if (cache.find(n) == cache.end()) {
            cache[n] = climbStairs1(n-1, cache) + climbStairs1(n-2, cache);
        }
        return cache[n];
    }

    int climbStairs1(int n) {
        unordered_map<int, int> cache;
        return climbStairs1(n, cache);
    }

    // 2 Tabulation Technique
    int climbStairs2(int n) {
        int res[n+1];
        
        res[0] = 1;
        res[1] = 1;

        for(int i = 2; i <= n; i++){
            res[i] = res[i-1] + res[i-2];
        }

        return res[n];
    }
};