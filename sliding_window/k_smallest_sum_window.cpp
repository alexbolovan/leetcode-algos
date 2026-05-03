// CP algorithm for keeping the sum of the k smallest or largest in a sliding window
// Necessary for some hard problems
// You could you lazy propogation with heap but the code for that is often alot more disgusting (this one is already pretty bad :( )

// Essentially this algorithm should come to mind whenever where you have to repeatedly make a query for max, min, sum, median, etc in a sliding window



// std::prev means keep the iterator one before the currently passed in iterator (good way to getting the last iterator that is not end())

#include "../includes.h"

using namespace std;

struct SmartWindow{
        int K;
        multiset<int> low, high;
        long long sumLow = 0;

        SmartWindow(int k) : K(k) {}

        int windowSize() const{
            return (int)low.size() + (int)high.size();
        }
        void rebalance() {
            int need = min(K, windowSize());

            while((int)low.size() > need){
                auto it = prev(low.end());
                int x = *it;
                low.erase(it);
                sumLow -= x;
                high.insert(x);
            }
            while((int)low.size() < need && !high.empty()){
                auto it = high.begin();
                int x = *it;
                high.erase(it);
                low.insert(x);
                sumLow += x;
            }
        }
        void add(int x){
            if(low.empty() || x <= *prev(low.end())){
                low.insert(x);
                sumLow += x;
            }
            else{
                high.insert(x);
            }
            rebalance();
        }
        void remove(int x){
            auto itLow = low.find(x);
            if(itLow != low.end()){
                low.erase(itLow);
                sumLow -= x;
            }
            else{
                auto itHigh = high.find(x);
                if(itHigh != high.end()){
                    high.erase(itHigh);
                }
            }
            rebalance();
        }
        long long query() const{
            return sumLow;
        }
    };
