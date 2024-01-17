#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class RandomizedSet {
public:
    vector<int> vectorSet;
    unordered_map<int,int> indexMap;

    RandomizedSet() {
        ios_base::sync_with_stdio(false);
    }
    
    bool search(int val){
        if(indexMap.find(val) != indexMap.end()){
            return true;
        }

        return false;
    }

    bool insert(int val) {
        if(search(val)){
            return false;
        }

        vectorSet.push_back(val);
        indexMap[val] = vectorSet.size()-1;

        return true;
    }
    
    bool remove(int val) {
        if(!search(val)){
            return false;
        }

        auto it = indexMap.find(val);

        vectorSet[it->second] = vectorSet.back();
        vectorSet.pop_back();

        indexMap[vectorSet[it->second]] = it->second;
        indexMap.erase(val);

        return true;
    }
    
    int getRandom() {
        return vectorSet[rand() % vectorSet.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);s
 * int param_3 = obj->getRandom();
 */