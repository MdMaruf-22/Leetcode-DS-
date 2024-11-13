class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> freq(26, 0);
        for(char c : s1)
            freq[c - 'a']++;
        
        for(int i = 0; i < s1.size(); i++)
            freq[s2[i] - 'a']--;
        if(allZero(freq)) return true;
        for(int i = s1.size(); i < s2.size(); i++) {
            int newChar = s2[i];
            int oldChar = s2[i - s1.size()];

            freq[newChar - 'a']--;
            freq[oldChar - 'a']++;

            if(allZero(freq)) return true;
        }

        return false;
    }

    bool allZero(vector<int>& freq) {
        for(int f : freq) {
            if(f != 0)
                return false;
        }
        return true;
    }
};