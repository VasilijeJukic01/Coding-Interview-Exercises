class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
       int n = s.size();
       
       auto cmp = [](const string& x, const string& y) {
           if (x.size() != y.size()) return x.size() > y.size();
           return x > y;
       };
       
       priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
      
       int ones = 0; 
       int left = 0;
       for (int right = 0; right < n; right++){
           if (s[right] == '1') ones++;
           while (ones > k) {
               if (s[left] == '1') ones--;
               left++;
           }
           while (ones == k && s[left] == '0') {
               left++;
           }
           if (ones == k) {
               pq.push(s.substr(left, right - left + 1));
           }
       }
       
       if (pq.empty()) return "";
       return pq.top();
    }
};