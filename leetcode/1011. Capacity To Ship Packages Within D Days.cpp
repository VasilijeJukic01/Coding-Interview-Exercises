class Solution {
public:
    bool can(vector<int>& weights, int days, int mid){
        int counter = 1;
        int sum = 0;

        for(int i = 0; i < weights.size(); i++){
            if (weights[i] > mid) return false;
            sum += weights[i];
            if(sum > mid) {
                counter++;
                sum = weights[i];
            }
        }

        if(counter <= days) return true;
        else return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int start = 1, end = 1;
        for(int i = 0; i < weights.size(); i++){
            end += weights[i];
        }

        int minCap = 0;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(can(weights, days, mid)){
                end = mid - 1;
                minCap = mid;
            }
            else start = mid + 1;
        }

        return minCap;

    }
};