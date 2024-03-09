class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // This unordered set is used to store the characters that are currently in the 
        // longest substring without repeating characters.
        std::unordered_set<char> charSet;
      
        // The starting index of the substring.
        int start = 0;
        // The length of the longest substring without repeating characters.
        int maxLength = 0;
      
        // Iterate over the string.
        for (int end = 0; end < s.size(); ++end) {
            // If the character at the current ending index of the substring already exists
            // in the character set, continue to remove characters from the start of the
            // substring until the character is no longer in the set.
            while (charSet.count(s[end])) {
                charSet.erase(s[start]);
                start += 1;
            }
          
            // Insert the current character into the set.
            charSet.insert(s[end]);
          
            // Calculate the length of the current substring and update maxLength
            // if this length is the largest we've found so far.
            maxLength = std::max(maxLength, end - start + 1);
        }
        // Return the length of the longest substring found.
        return maxLength;
    }
};