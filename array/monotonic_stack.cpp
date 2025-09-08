#include "includes.h"

using namespace std;

// ----- Monotonic Stack Helpers (O(n)) -----
// For all functions:
//   A = input array, n = A.size()
//   Returns vector<int> of indices (or -1 if none).

// Next Greater Element to the RIGHT (strictly greater)
vector<int> nextGreaterRight(const vector<int>& A) {
    int n = (int)A.size();
    vector<int> nxt(n, -1);
    vector<int> st; // decreasing stack of indices (A[st.top()] strictly desc)
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && A[i] > A[st.back()]) {
            nxt[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    return nxt;
}

// Previous Greater Element to the LEFT (strictly greater)
vector<int> prevGreaterLeft(const vector<int>& A) {
    int n = (int)A.size();
    vector<int> prv(n, -1);
    vector<int> st; // decreasing stack
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && A[st.back()] <= A[i]) st.pop_back();
        prv[i] = st.empty() ? -1 : st.back();
        st.push_back(i);
    }
    return prv;
}

// Next Smaller Element to the RIGHT (strictly smaller)
vector<int> nextSmallerRight(const vector<int>& A) {
    int n = (int)A.size();
    vector<int> nxt(n, -1);
    vector<int> st; // increasing stack of indices
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && A[i] < A[st.back()]) {
            nxt[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    return nxt;
}

// Previous Smaller Element to the LEFT (strictly smaller)
vector<int> prevSmallerLeft(const vector<int>& A) {
    int n = (int)A.size();
    vector<int> prv(n, -1);
    vector<int> st; // increasing stack
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && A[st.back()] >= A[i]) st.pop_back();
        prv[i] = st.empty() ? -1 : st.back();
        st.push_back(i);
    }
    return prv;
}

// ----- Patterns / Examples -----

// Daily Temperatures-style: days to next greater temperature
vector<int> daysToWarmer(const vector<int>& T) {
    int n = (int)T.size();
    vector<int> ans(n, 0);
    vector<int> st; // decreasing by T
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && T[i] > T[st.back()]) {
            int j = st.back(); st.pop_back();
            ans[j] = i - j;
        }
        st.push_back(i);
    }
    return ans;
}

// Largest Rectangle in Histogram (heights)
int largestRectangleArea(const vector<int>& H) {
    int n = (int)H.size();
    vector<int> st; // increasing by H
    long long best = 0;
    for (int i = 0; i <= n; ++i) {
        long long cur = (i == n ? 0 : H[i]);
        while (!st.empty() && cur < H[st.back()]) {
            int h = H[st.back()]; st.pop_back();
            int l = st.empty() ? 0 : st.back() + 1;
            int r = i - 1;
            best = max(best, 1LL * h * (r - l + 1));
        }
        st.push_back(i);
    }
    return (int)best;
}

// Next Greater Element values (not indices). If none, -1.
vector<int> nextGreaterValues(const vector<int>& A) {
    int n = (int)A.size();
    vector<int> ans(n, -1);
    vector<int> st; // decreasing by value
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && A[i] > A[st.back()]) {
            ans[st.back()] = A[i];
            st.pop_back();
        }
        st.push_back(i);
    }
    return ans;
}

// Span example (e.g., Stock Span)
vector<int> spanGreaterEqualLeft(const vector<int>& A) {
    int n = (int)A.size();
    vector<int> span(n, 1);
    vector<int> st; // decreasing by A
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && A[st.back()] <= A[i]) st.pop_back();
        span[i] = st.empty() ? (i + 1) : (i - st.back());
        st.push_back(i);
    }
    return span;
}

// ---- Usage sketch ----
// auto ngr = nextGreaterRight(A);    // index of next greater to the right
// auto psl = prevSmallerLeft(A);     // index of prev smaller to the left
// auto ans = largestRectangleArea(H); // histogram
