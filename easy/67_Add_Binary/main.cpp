#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int idxA = a.size() - 1;
        int idxB = b.size() - 1;

        int carry = 0;
        string res;

        for (; idxA >= 0 || idxB >= 0; --idxA, --idxB) {
            int intA = (idxA >= 0) ? a[idxA] - '0' : 0;
            int intB = (idxB >= 0) ? b[idxB] - '0' : 0;
            int sum = intA + intB + carry;
            carry = sum >> 1;
            sum %= 2;
            res.push_back(static_cast<char>(sum + '0'));
        }

        if (carry > 0) {
            res.push_back('1');
        }

        reverse(res.begin(), res.end());

        return res;
    }
};