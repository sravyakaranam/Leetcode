class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;  // This will track where to place the next character in the `chars` vector.
        int i = 0;  // This will scan through the `chars` vector.

        while (i < chars.size()) {
            char currentChar = chars[i];
            int count = 0;
            // Count occurrences of the current character.
            while (i < chars.size() && chars[i] == currentChar) {
                i++;
                count++;
            }
            // Place the character into the `chars` vector at the index position.
            chars[index++] = currentChar;
            // If the count is more than 1, we need to add the count to the `chars` vector.
            if (count > 1) {
                // Convert count to a string and then add each character of this string to the `chars` vector.
                for (char c : to_string(count)) {
                    chars[index++] = c;
                }
            }
        }
        // Resize the vector to the new size.
        chars.resize(index);
        return index; // The size of the compressed list.
    }
};
