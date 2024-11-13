class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;
        int maxVowelCount = 0;
        int strLength = s.size();

        for (int i = 0; i < k; ++i)
            count += isVowel(s[i]); 
      
        maxVowelCount = count;

        for (int i = k; i < strLength; ++i) {
            count += isVowel(s[i]);
            count -= isVowel(s[i - k]);
            maxVowelCount = max(maxVowelCount, count);
        }

        return maxVowelCount;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
