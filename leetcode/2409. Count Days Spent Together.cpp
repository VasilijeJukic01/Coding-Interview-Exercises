class Solution {
    array<int, 4> getData(string& date1, string& date2) {
        string monthFrom = date1.substr(0, 2);
        string monthTo = date2.substr(0, 2);
        string dayFrom = date1.substr(3, 2);
        string dayTo = date2.substr(3, 2);

        int monthF = stoi(monthFrom), monthT = stoi(monthTo);
        int dayF = stoi(dayFrom), dayT = stoi(dayTo);

        return {monthF, monthT, dayF, dayT};
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> monthDays = {
            0, 31, 28, 31, 
            30, 31, 30, 31, 
            31, 30, 31, 30, 31
        };

        auto [AmonthF, AmonthT, AdayF, AdayT] = getData(arriveAlice, leaveAlice);
        auto [BmonthF, BmonthT, BdayF, BdayT] = getData(arriveBob, leaveBob);

        if (AmonthT < BmonthF || BmonthT < AmonthF) return 0;

        int startMonth = max(AmonthF, BmonthF);
        int endMonth = min(AmonthT, BmonthT);
        int startDay, endDay;

        if (AmonthF == BmonthF) startDay = max(AdayF, BdayF);
        else if (AmonthF < BmonthF) startDay = BdayF;
        else startDay = AdayF;

        if (AmonthT == BmonthT) endDay = min(AdayT, BdayT);
        else if (AmonthT > BmonthT) endDay = BdayT;
        else endDay = AdayT;
        
        int totalDays = 0;
        if (startMonth == endMonth) {
            totalDays += endDay - startDay + 1;
        }
        else {
            totalDays += monthDays[startMonth] - startDay + 1;
            totalDays += endDay;
            for (int m = startMonth + 1; m <= endMonth - 1; m++) {
                totalDays += monthDays[m];
            }
        }

        if (totalDays <= 0) return 0;
        return totalDays;
    }
};