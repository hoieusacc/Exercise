#include <iostream>
using namespace std;

int strlen_custom(char *a) {
    int len = 0;
    while (*a++) len++;
    return len;
}

void reverse(char *a) {
    int len = strlen_custom(a);
    char *left = a, *right = a + len - 1;
    while (left < right) {
        char temp = *left;
        *left++ = *right;
        *right-- = temp;
    }
}

void delete_char(char *a, char c) {
    char *src = a, *dst = a;
    while (*src) {
        if (*src != c) *dst++ = *src;
        src++;
    }
    *dst = '\0';
}

void pad_right(char *a, int n) {
    int len = strlen_custom(a);
    if (len >= n) return;
    while (len < n) a[len++] = ' ';
    a[len] = '\0';
}

void pad_left(char *a, int n) {
    int len = strlen_custom(a);
    if (len >= n) return;
    int shift = n - len;
    for (int i = len; i >= 0; i--) a[i + shift] = a[i];
    for (int i = 0; i < shift; i++) a[i] = ' ';
}

void truncate(char *a, int n) {
    if (strlen_custom(a) > n) a[n] = '\0';
}

bool is_palindrome(char *a) {
    int len = strlen_custom(a);
    char *left = a, *right = a + len - 1;
    while (left < right) {
        if (*left++ != *right--) return false;
    }
    return true;
}

void trim_left(char *a) {
    char *start = a;
    while (*start == ' ') start++;
    char *dst = a;
    while (*start) *dst++ = *start++;
    *dst = '\0';
}

void trim_right(char *a) {
    int len = strlen_custom(a);
    char *end = a + len - 1;
    while (end >= a && *end == ' ') end--;
    *(end + 1) = '\0';
}

int main() {
    char str1[] = "hello world";
    char str2[] = "racecar";
    char str3[] = "   trim left test";
    char str4[] = "trim right test   ";
    char str5[] = "padding test";
    char str6[] = "truncate this string";
    
    reverse(str1);
    cout << "Reversed: " << str1 << endl;
    
    delete_char(str1, 'l');
    cout << "Deleted 'l': " << str1 << endl;
    
    pad_right(str5, 20);
    cout << "Pad right: " << str5 << "!" << endl;
    
    pad_left(str5, 25);
    cout << "Pad left: " << str5 << "!" << endl;
    
    truncate(str6, 10);
    cout << "Truncated: " << str6 << endl;
    
    cout << "Palindrome check (racecar): " << (is_palindrome(str2) ? "Yes" : "No") << endl;
    
    trim_left(str3);
    cout << "Trim left: " << str3 << endl;
    
    trim_right(str4);
    cout << "Trim right: " << str4 << endl;
    
    return 0;
}
