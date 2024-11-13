class Solution {
public:
    // Check if string 's' can be converted to string 't' with exactly one edit
    bool isOneEditDistance(string s, string t) {
        int lenS = s.length(), lenT = t.length(); // Use more descriptive variable names

        // Guarantee that 's' is not shorter than 't'
        if (lenS < lenT) return isOneEditDistance(t, s);

        // If the strings differ in length by more than 1, it can't be one edit
        if (lenS - lenT > 1) return false;

        // Iterate through characters in both strings
        for (int i = 0; i < lenT; ++i) {
            // If characters don't match, check the types of possible one edit
            if (s[i] != t[i]) {
                // If lengths are the same, check for replace operation
                if (lenS == lenT) return s.substr(i + 1) == t.substr(i + 1);
                // If lengths differ, check for insert operation
                return s.substr(i + 1) == t.substr(i);
            }
        }

        // If all previous characters matched, check for append operation
        return lenS == lenT + 1;
    }
};