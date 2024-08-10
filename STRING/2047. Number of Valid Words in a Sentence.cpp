class Solution {
public:
    int countValidWords(string sentence) {
        vector<string> words;
        string word;

        // Split the sentence into words
        stringstream ss(sentence);
        while (ss >> word) {
            words.push_back(word);
        }

        int validCount = 0;

        // Check each word
        for (string w : words) {
            int hyphenCount = 0;
            int punctuationCount = 0;
            bool isValid = true;

            for (int i = 0; i < w.length(); i++) {
                if (isdigit(w[i])) {
                    isValid = false;
                    break;
                }

                if (w[i] == '-') {
                    hyphenCount++;
                    // Hyphen must be surrounded by letters and not at the start or end
                    if (hyphenCount > 1 || i == 0 || i == w.length() - 1 || !isalpha(w[i-1]) || !isalpha(w[i+1])) {
                        isValid = false;
                        break;
                    }
                }

                if (w[i] == '!' || w[i] == '.' || w[i] == ',') {
                    punctuationCount++;
                    // Punctuation must be at the end and must appear only once
                    if (punctuationCount > 1 || i != w.length() - 1) {
                        isValid = false;
                        break;
                    }
                }
            }

            if (isValid)//&& hyphenCount <= 1 && punctuationCount <= 1) {
             {   validCount++;
            }
        }

        return validCount;
    }
};
