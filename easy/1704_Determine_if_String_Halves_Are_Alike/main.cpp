#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt = 0,n = s.size();
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        for(int  i = 0;i<n;i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                cnt++;
        }
        int c = 0;
        for(int i = 0;i<n/2;i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                c++;
        }
        if(2*c==cnt)
            return true;
        else
            return false;
    }
};