class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int, vector<int>, greater<int>> pqEven;
        priority_queue<int, vector<int>, greater<int>> pqOdd;

        int copy = num;
        while (copy) {
            int digit = copy % 10;
            if (digit & 1) pqOdd.push(digit);
            else pqEven.push(digit);

            copy /= 10;
        }

        long long largest = 0;
        long long p = 1;
        while (num) {
            int digit = num % 10;

            if (digit & 1) {
                digit = pqOdd.top();
                pqOdd.pop();
            }
            else {
                digit = pqEven.top();
                pqEven.pop();
            }

            largest = largest + digit * p;
            p *= 10;
            num /= 10;
        }

        return largest;
    }
};