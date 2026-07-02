#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        
        while (n != 1 && !seen.contains(n)) {
            seen.insert(n);

            int sum = 0;
            while (n != 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};
