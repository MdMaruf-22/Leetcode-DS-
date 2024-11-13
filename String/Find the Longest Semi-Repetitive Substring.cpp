class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int cnt = 0;
        int left = 0, repeat = 0;
        for (int right = 0; right < s.size(); right++) {
            if (right > 0 && s[right] == s[right - 1]) {
                repeat++;
            }
            while (repeat > 1) {
                if (left + 1 < s.size() && s[left] == s[left + 1]) {
                    --repeat;
                }
                left++;
            }
            cnt = max(cnt, right - left + 1);
        }
        return cnt;
    }
};
