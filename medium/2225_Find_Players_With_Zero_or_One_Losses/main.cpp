#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> map;

        for(int i = 0; i < matches.size(); i++) {
            map[matches[i][1]]++;
        }

        vector<int> zeroLost;
        vector<int> oneLost;

        for(int i = 0; i < matches.size(); i++){
            if(map.find(matches[i][0]) == map.end()){
                zeroLost.push_back(matches[i][0]);
                map[matches[i][0]] = 2;
            }

            if(map[matches[i][1]] == 1){
                oneLost.push_back(matches[i][1]);
            }
        }

        sort(zeroLost.begin(), zeroLost.end());    
        sort(oneLost.begin(), oneLost.end());

        return {zeroLost, oneLost};
    }
};