#include <stdbool.h>

bool isPalindrome(int x) {
    char buf[12];
    int i, len;
    sprintf(buf, "%d", x);
    len = strlen(buf);
    for(i = 0;i<(len / 2);i++){

        if(buf[i] != buf[len - i - 1])
            return 0;
    } 
    return 1;
}