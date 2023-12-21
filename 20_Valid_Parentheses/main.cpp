#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string stack = "";
        for(char c : s){
            if(c == '('){
                stack.push_back(')');
            } else if(c == '['){
                stack.push_back(']');
            } else if(c == '{'){
                stack.push_back('}');
            } else if(stack.empty()){
                return 0;
            } else
            if(stack.back() != c){
                return 0;
            } else{
                stack.pop_back();
            }
        }
        return stack.empty();
    }
};