class HitCounter {
    const int CAP = 300;
    vector<array<int, 2>> data;
public:
    HitCounter() {
        this->data.reisze(CAP, {0, 0});
    }

    /**
     * @param timestamp: the timestamp
     * @return: nothing
     */
    void hit(int timestamp) {
        int i = timestamp % CAP;
        if (data[i][0] != timestamp) {
            data[i] = {timestamp, 1};
        }
        else data[i][1]++;
    }

    /**
     * @param timestamp: the timestamp
     * @return: the count of hits in recent 300 seconds
     */
    int getHits(int timestamp) {
        int total = 0;
        for (int i = 0; i < CAP; i++) {
            if (timestamp - data[i][0] < 300) {
                total += data[i][1];
            }
        }
        return total;
    }
};