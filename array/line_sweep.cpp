#include "../includes.h"

using namespace std;

class Interval
{
public:
    int start, end;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};


// We are given a list of intervals and we have to find the total numbers of rooms (or days if we assume only one room exists)
//      such that all meetings can occur wihtout having two meetings on the same day at the same time 
class Solution
{
public:
    int minMeetingRooms(vector<Interval> &its)
    {
        vector<vector<int>> it;
        for (int i = 0; i < its.size(); ++i)
        {
            it.push_back({its[i].start, its[i].end});
        }

        const int k = it.size();

        if (k == 0)
            return 0;

        vector<pair<int, int>> lineSweep;

        // +1 for the starts and -1 for the ends
        // this will be used in the last part where the process will be described in detail
        for (auto &v : it)
        {
            lineSweep.push_back({v[0], 1});
            lineSweep.push_back({v[1], -1});
        }

        // start by order the intervals by the start value
        sort(lineSweep.begin(), lineSweep.end(), [](pair<int, int> &v1, pair<int, int> &v2)
             {
            if (v1.first != v2.first) {
                return v1.first < v2.first;
            } else {
                return v1.second < v2.second;
            } });



        // the idea here is that we are trying to find the maximum of overlapping rooms
        // by using +1 and -1, we are finding the maximum value we reach and that will be the number of rooms/days
        // it is to be noted at the end count will always be 0
        int cnt = 0;
        int mx = 0;
        for (auto &p : lineSweep)
        {
            cnt += p.second;
            mx = max(cnt, mx);
        }

        return mx;

        return cnt;
    }
};
