class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;

        int counter = 0;
        char prev = chars[0];
        for (int read = 0; read < chars.size(); read++) {
            if (chars[read] == prev) counter++;
            else {
                chars[write++] = prev;
                if (counter > 1) {
                    string n = to_string(counter);
                    for (int k = 0; k < n.size(); k++) {
                        chars[write++] = n[k];
                    }
                }
                counter = 1;
            }
            prev = chars[read];
        }

        chars[write++] = prev;
        if (counter > 1) {
            string n = to_string(counter);
            for (int k = 0; k < n.size(); k++) {
                chars[write++] = n[k];
            }
        }

        return write;
    }
};