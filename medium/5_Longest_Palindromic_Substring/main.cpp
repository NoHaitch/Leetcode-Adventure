// #include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len == 0 || len == 1){
            return s;
        }

        vector<int> res1(len, 1);
        vector<int> res2(len - 1, 1);
        int max = 1;

        for(int i = 1; i < len - 1; i++){
            int curr = 1;
            int neighbor = 1;
            int leftIdx = i - neighbor;
            int rightIdx = i + neighbor;

            while(leftIdx >= 0 && rightIdx <= len - 1){
                if(s[leftIdx] == s[rightIdx]){
                    curr += 2;
                    neighbor++;
                    leftIdx = i - neighbor;
                    rightIdx = i + neighbor;
                } else{
                    break;
                }
            }

            res1[i] = curr;
            if(curr > max){
                max = curr;
            }
        }

        // Handle palindrom with no middle character
        for(int i = 0; i < len - 1; i++){
            if(s[i] == s[i+1]){
                int curr = 2;
                int neighbor = 1;
                int leftIdx = i - neighbor;
                int rightIdx = i + neighbor + 1;

                while(leftIdx >= 0 && rightIdx <= len - 1){
                    if(s[leftIdx] == s[rightIdx]){
                        curr += 2;
                        neighbor++;
                        leftIdx = i - neighbor;
                        rightIdx = i + neighbor + 1;
                    } else{
                        break;
                    }
                }

                res2[i] = curr;
                
                if(curr > max){
                    max = curr;
                }
            }
        }


        // cout << "[";
        // for(int i = 0; i < s.size(); i++){
        //     cout << res1[i];
        //     if(i != s.size() - 1){
        //         cout << ", ";
        //     }
        // }
        // cout << "]" << endl;
        
        for(int i = 0; i < len; i++){
            if(res1[i] == max){
                int bottomIdx = i - ((max - 1) / 2);
                return s.substr(bottomIdx, max);
            }
        }

        // Handle palindrom with no middle character 
        for(int i = 0; i < len - 1; i++){
            if(res2[i] == max){
                int bottomIdx = i - ((max - 1) / 2);
                return s.substr(bottomIdx, max);
            }
        }
        
        return s;
    }
};