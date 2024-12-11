#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* Calculate the index of the current flattened position */
/* We need to use gEdgeSize since if we just use i and j, the end of the row will have the same index as the first element of the next row (which is obv. wrong)*/
int getIdx(int i, int j, int gEdgeSize) {
    return i * gEdgeSize + j;
} 


typedef pair<int, int> pii;
void flatten2dArray(const vector<vector<int>>& grid) {
    int gEdgeSize =  grid.size();
    
    /* Using a dirs map of pairs makes it easy to expand if you ever need diagonals*/
    vector<pii> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < gEdgeSize; ++i) {
        for (int j = 0; j < gEdgeSize; ++j) {
            int nodeIdx = getIdx(i, j, gEdgeSize); // This would likely be used in the "do something" component if you need to access the curren idx

            for (auto dir : dirs) {
                /* Getting the index of the current direction we are iterating on */
                int ni = i + dir.first;
                int nj = j + dir.second;
                
                /* Check whether this current "move" is in bounds */
                if (ni >= 0 and ni < gEdgeSize and nj >= 0 and nj < gEdgeSize) {
                    cout << "do something..." << endl; 
                }
                
            }

        }
    }

}


int main() {
    vector<vector<int>> sample = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    flatten2dArray(sample);

}
