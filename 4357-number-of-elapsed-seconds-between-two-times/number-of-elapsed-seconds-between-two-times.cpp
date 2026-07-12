class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int h_st = startTime[0]-'0';
        h_st = h_st*10 + (startTime[1]-'0');

        int min_st = startTime[3]-'0';
        min_st = min_st*10 + startTime[4]-'0';

        int sec_st = startTime[6]-'0';
        sec_st = sec_st*10 + startTime[7]-'0';

        int h_end = endTime[0]-'0';
        h_end = h_end*10 + (endTime[1]-'0');

        int min_end = endTime[3]-'0';
        min_end = min_end*10 + endTime[4]-'0';

        int sec_end = endTime[6]-'0';
        sec_end = sec_end*10 + endTime[7]-'0';

        int st_sec = (h_st*3600) + (min_st*60) + (sec_st);
        int end_sec = (h_end*3600) + (min_end*60) + (sec_end);

        return end_sec - st_sec;

    }
};