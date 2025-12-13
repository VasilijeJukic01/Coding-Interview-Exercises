class Solution {
public:
    bool isCodeValid(string code) {
        regex pattern("^[A-Za-z0-9_]+$");
        return regex_match(code, pattern);
    }

    bool isLineValid(string line) {
        regex pattern("\\b(electronics|grocery|pharmacy|restaurant)\\b");
        return regex_match(line, pattern);
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        // {BusinessLine, Code}
        vector<pair<string, string>> validItems;

        for (int i = 0; i < code.size(); i++) {
            if (!isActive[i]) continue;
            if (isCodeValid(code[i]) && isLineValid(businessLine[i])) {
                validItems.push_back({businessLine[i], code[i]});
            }
        }
        
        sort(validItems.begin(), validItems.end());

        vector<string> result;
        for (auto& item : validItems) {
            result.push_back(item.second);
        }

        return result;
    }
};