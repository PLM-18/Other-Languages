#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int n = s.size();
        int length = 0;
        int start = 0;
        std::unordered_map<char, int> last_seen;
        for (int i = 0; i < n; i++) {
            if (last_seen.find(s[i]) != last_seen.end()) {
                start = std::max(start, last_seen[s[i]] + 1);
            }
            last_seen[s[i]] = i;
            length = std::max(length, i - start + 1);
        }
        return length;        
    }
};

int main() {
    Solution solution;
    std::string s = "abcabcbb";
    std::cout << solution.lengthOfLongestSubstring(s) << std::endl;
    std::cout<< solution.lengthOfLongestSubstring("bbbbb") << std::endl;
    return 0;
}