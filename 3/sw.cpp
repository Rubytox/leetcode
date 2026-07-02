#include <unordered_map>

class Solution {

public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        int window_start = 0;
        int window_end = 0;

        int max = 0;
        int n = s.length();
        while (window_end < n && window_start < n) {
            while (window_end < n) {
                char c = s[window_end];
                if (seen[c] != 0)
                    break;
                seen[c]++;
                window_end++;
            }

            if (max < window_end - window_start)
                max = window_end - window_start;
            
            seen[s[window_start++]] = 0;
        }
        return max;
    }
};
