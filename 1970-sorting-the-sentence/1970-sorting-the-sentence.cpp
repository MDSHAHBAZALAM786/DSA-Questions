class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(10); // Array to store words in correct order
        string word = "";
        int count = 0; // To count number of words

        for (char c : s) {
            if (c == ' ') {
                int pos = word.back() - '0'; // Get position from last character
                word.pop_back(); // Remove the digit
                words[pos] = word; // Store in correct position
                word = ""; // Reset word
                count++; // Increment word count
            } else {
                word += c;
            }
        }

        // For the last word
        int pos = word.back() - '0';
        word.pop_back();
        words[pos] = word;
        count++;

        // Construct the sorted sentence
        string result = words[1];
        for (int i = 2; i <= count; i++) {
            result += " " + words[i];
        }

        return result;
    }
};
