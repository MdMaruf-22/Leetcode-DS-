class Solution {
public:
    // Determine if two sentences are similar according to the problem's definition.
    bool areSentencesSimilar(std::string sentence1, std::string sentence2) {
        // Split the sentences into words.
        std::vector<std::string> words1 = split(sentence1, ' ');
        std::vector<std::string> words2 = split(sentence2, ' ');

        // Ensure that words1 is the longer sentence to simplify the logic.
        if (words1.size() < words2.size()) {
            std::swap(words1, words2);
        }

        int length1 = words1.size(); // Length of the longer sentence.
        int length2 = words2.size(); // Length of the shorter sentence.

        int prefixMatch = 0; // Number of matching words from the start.
        int suffixMatch = 0; // Number of matching words from the end.

        // Count the number of matching words from the start of both sentences.
        while (prefixMatch < length2 && words1[prefixMatch] == words2[prefixMatch]) {
            ++prefixMatch;
        }

        // Count the number of matching words from the end of both sentences.
        while (suffixMatch < length2 && words1[length1 - 1 - suffixMatch] == words2[length2 - 1 - suffixMatch]) {
            ++suffixMatch;
        }

        // If the sum of matches is greater than or equal to length2, the sentences are similar.
        return prefixMatch + suffixMatch >= length2;
    }

private:
    // Utility function to split a string by a delimiter, returning a vector of words.
    std::vector<std::string> split(std::string& s, char delimiter) {
        std::stringstream stream(s);
        std::string item;
        std::vector<std::string> result;

        while (std::getline(stream, item, delimiter)) {
            result.emplace_back(item);
        }

        return result;
    }
};