#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> s_map;
        for (auto c : s)
            s_map[c]++;

        for (auto c : t)
            if (--s_map[c] < 0)
                return false;
        
        return true;
    }
};
