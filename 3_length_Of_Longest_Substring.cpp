#include <bits/stdc++.h>
using namespace std;

pair<int, string> lengthOfLongestSubstring(string s) {
    int n = s.length();
    int maxlength = 0;
    unordered_set<char> charSet;
    int left = 0;
    int start = 0;  // Starting index of the longest substring
    int end = 0;    // Ending index of the longest substring

    for (int right = 0; right < n; right++) {
        if (charSet.count(s[right]) == 0) {
            charSet.insert(s[right]);
            if (right - left + 1 > maxlength) {
                maxlength = right - left + 1;
                start = left;
                end = right;
            }
        } else {
            while (charSet.count(s[right]) > 0) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
        }
    }

    string longestSubstring = s.substr(start, end - start + 1);
    return {maxlength, longestSubstring};
}

int main() {
    string s = "abcdeabcbb";
    pair<int, string> result = lengthOfLongestSubstring(s);
    int maxLength = result.first;
    string longestSubstring = result.second;

    cout << "Longest substring of non-repeating characters: " << longestSubstring << endl;
    cout << "Length of the longest substring: " << maxLength << endl;

    return 0;
}
