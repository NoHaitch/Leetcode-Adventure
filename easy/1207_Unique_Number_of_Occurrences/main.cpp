#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occur;
        
        for(auto& elmt : arr){
            occur[elmt]++;
        }

        vector<int> seen;
        unordered_map<int, int>::iterator it = occur.begin();

        while(it != occur.end()){
            if(find(seen.begin(), seen.end(), it->second) != seen.end()){
                return false;
            }

            seen.push_back(it->second);
            it++;
        }

        return true;
    }
};