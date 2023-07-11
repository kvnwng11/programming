class Solution {
private:
    unordered_map<string, int> count;
    int word_length = 0;
    int string_size = 0;
    int substring_size = 0;
    int num_words = 0;
public:
    void slidingWindow(int left, string &s, vector<int> &ans) {
        unordered_map<string, int> found;
        int words_used = 0;
        bool excess_word = 0;

        for (int right = left; right <= s.size() - word_length; right += word_length) {
            // Get current word
            string curr = s.substr(right, word_length);

            // This word is not in our list
            if (count.find(curr) == count.end()) {
                found.clear();
                words_used = 0;
                excess_word = false;
                left = right + word_length;
            }
            // This word is in our list
            else {
                // If widndow is full or have extra word
                while (right - left == substring_size or excess_word) {
                    string left_word = s.substr(left, word_length);
                    left += word_length;
                    found[left_word] -= 1;

                    if (count[left_word] <= found[left_word]) {
                        excess_word = false;
                    }
                    else {
                        words_used--;
                    }
                }

                found[curr] += 1;
                if (found[curr] <= count[curr])
                    words_used++;
                else
                    excess_word = true;

                if (words_used == num_words and !excess_word and find(ans.begin(), ans.end(), left) == ans.end())
                    ans.push_back(left);

            }
        }
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        // initialize
        string_size = s.size();
        num_words = words.size();
        word_length = words[0].size();
        substring_size = word_length * words.size();

        // initialize word count
        for (int i=0; i<words.size(); ++i) {
            count[words[i]] += 1;
        }

        // check all substrings
        vector<int> ans;
        if (substring_size > string_size)
            return ans;
        for (int i=0; i <= word_length; ++i) {
            slidingWindow(i, s, ans);
        }

        return ans; 
    }
};