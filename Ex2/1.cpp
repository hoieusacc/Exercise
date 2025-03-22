#include <iostream>
#include <cstring>

using namespace std;

int countOccurrences(const char *sub, const char *str) {
    int count = 0;
    int subLen = strlen(sub);
    int strLen = strlen(str);
    
    for (int i = 0; i <= strLen - subLen; i++) {
        bool match = true;
        for (int j = 0; j < subLen; j++) {
            if (str[i + j] != sub[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            count++;
        }
    }
    
    return count;
}

int main(int argc, char *argv[]) {
    int occurrences = countOccurrences(argv[1], argv[2]);
    
    cout << "Occurrences: " << occurrences << endl;
    
    return 0;
}
