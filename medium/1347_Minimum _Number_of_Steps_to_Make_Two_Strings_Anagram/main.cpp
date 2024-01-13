#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int m[26]{};

        for (const auto& e : s) {
            ++ m[e - 'a'];
        }
        
        for (const auto& e : t) {
            -- m[e - 'a'];
        }
        
        return accumulate(m, m + 26, 0, [] (int acc, int i) {return acc + std::abs(i);})/2;
    }
};