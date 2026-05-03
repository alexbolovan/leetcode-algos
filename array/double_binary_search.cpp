#include "../includes.h"
using namespace std;
class Solution {
public:
    enum class RES { EQUAL, ABOVE, BELOW };

    RES are_eq(long double mid, const vector<vector<int>>& squares) {
        long double above = 0;
        long double below = 0;

        for (const auto& sq : squares) {
            long double y = sq[1];
            long double len = sq[2];
            long double area = len * len;

            if (y >= mid) {
                above += area;
            } else if (y + len <= mid) {
                below += area;
            } else {
                below += (mid - y) * len;
                above += (y + len - mid) * len;
            }
        }

        long double diff = above - below;
        // EPS -> epsilon
        const long double EPS = 1e-9;
        /* On the really rare chance they are equal we can't just compare floating point numbers so we checking them via an epsilon  */        
        /* Funily enough we will almost never get the exact equality rather we will always just be close... */
        if (fabsl(diff) <= EPS) return RES::EQUAL;
        if (diff > 0) return RES::ABOVE;
        return RES::BELOW;
    }

    double separateSquares(vector<vector<int>>& squares) {
        long double l = 0, r = 0;

        for (const auto& sq : squares) {
            r = max(r, (long double)sq[1] + (long double)sq[2]);
        }
    
        while (r - l > 1e-6) {
            long double m = l + (r - l) / 2.0;
            auto res = are_eq(m, squares);

            if (res == RES::ABOVE) {
                l = m;
            } else {
                r = m;
            }
        }

        return (double)r;
    }
};
