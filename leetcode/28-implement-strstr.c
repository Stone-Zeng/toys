// 28. Implement strStr()
// https://leetcode.com/problems/implement-strstr/

#include <stdio.h>

int strLen(char * str) {
    int i = 0;
    while (str[i] != '\0')
        ++i;
    return i;
}

int strCmp(char * str1, char * str2, int len) {
    for (int i = 0; i < len ; ++i)
        if (str1[i] != str2[i]) return 0;
    return 1;
}

int strStr(char * haystack, char * needle) {
    if (! *needle) return 0;
    int haystack_len = strLen(haystack),
        needle_len   = strLen(needle);
    for (int i = 0; i <= haystack_len - needle_len; ++i)
        if (strCmp(haystack + i, needle, needle_len)) return i;
    return -1;
}

int main() {
    printf("%d\n", strStr("Hello", ""));
    printf("%d\n", strStr("Hello", "H"));
    printf("%d\n", strStr("Hello", "He"));
    printf("%d\n", strStr("Hello", "el"));
    printf("%d\n", strStr("Hello", "ll"));
    printf("%d\n", strStr("Hello", "l"));
    printf("%d\n", strStr("Hello", "lo"));
    printf("%d\n", strStr("HelloHelloHell0o", "l0"));
}
