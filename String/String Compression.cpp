class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(); // Length of the input vector
        int writeIndex = 0; // Index to write compressed characters
        int count = 0; // Count of consecutive repeating characters
        int readIndex = 0; // Index to read characters from the input vector

        while (readIndex < n) { // Iterate through the input vector
            chars[writeIndex] = chars[readIndex]; // Store the current character at writeIndex

            // Count consecutive repeating characters
            while (readIndex < n && chars[readIndex] == chars[writeIndex]) {
                readIndex++; // Move to the next character
                count++; // Increment the count of consecutive characters
            }

            // If count is greater than 1, encode it as characters
            if (count > 1) {
                string cntstr = to_string(count); // Convert count to string
                for (char c : cntstr) { // Iterate through the characters of the count string
                    writeIndex++; // Move to the next index to write
                    chars[writeIndex] = c; // Write the character representing count
                }
            }

            count = 0; // Reset count for the next group of characters
            writeIndex++; // Move to the next index to write compressed characters
        }

        return writeIndex; // Return the length of the compressed array
    }
};
