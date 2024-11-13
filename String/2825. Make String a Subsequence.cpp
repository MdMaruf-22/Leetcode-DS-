class Solution {
public:
    bool canMakeSubsequence(string s1, string s2) {
        int index = 0;
        int s2Length = s2.size();

        for (char currentChar : s1) {
            char nextChar = currentChar == 'z' ? 'a' : static_cast<char>(currentChar + 1);

            if (index < s2Length && (s2[index] == currentChar || s2[index] == nextChar)) {
                ++index;
            }
        }

        return index == s2Length;
    }
};
