#include <iostream>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int maxLen = 0, left = 0;
    for (int right = 0; right < s.size(); right++) {
        while (seen.find(s[right]) != seen.end()) {
            seen.erase(s[left++]);
        }
        seen.insert(s[right]);
        maxLen = max(maxLen, right - left);
    }
    return maxLen;
}
