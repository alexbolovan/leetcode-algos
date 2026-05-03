#include "../includes.h"
#include <format>

using namespace std;

template <class T>
class seg_tree {
  public:
    seg_tree(const vector<T>& in) : org_sz(in.size()), sz(get_size(in.size())), underlying(vector<T>(sz)) {
        construct_tree(in, 0, in.size() - 1, 0);
    }

    T query(int l, int r) {
        return query_min_range(l, r, 0, org_sz - 1, 0);
    }

    void update(int idx, T val) {
		return update_seg_tree(idx, val, 0, org_sz - 1, 0);
	}

  private:
    int org_sz;
    int sz;
    vector<T> underlying;

    void construct_tree(const vector<T>& org, int l, int r, int pos) {
        if (l == r) {
            underlying[pos] = org[l];
            return;
        }

        int mid = l + (r - l) / 2;

        construct_tree(org, l, mid, 2 * pos + 1);
        construct_tree(org, mid + 1, r, 2 * pos + 2);

        underlying[pos] = min(underlying[2 * pos + 1], underlying[2 * pos + 2]);
    }

    T query_min_range(const int ql, const int qr, int l, int r, int pos) {
        if (ql <= l && qr >= r) { // query fully within the range, return value
            return underlying[pos];
        }

        if (ql > r || qr < l) { // no overlap with the range, return dummy
            return INT_MAX;
        }

        int mid = l + (r - l) / 2;

        // split into two and query the two other ranges when partially cvered
        return min(query_min_range(ql, qr, l, mid, 2 * pos + 1), query_min_range(ql, qr, mid + 1, r, 2 * pos + 2));
    }

    void update_seg_tree(int idx, T val, int l, int r, int pos) {
        if (l == r) {
            underlying[pos] = val;
            return;
		}

		int mid = l + (r - l) / 2;
		if (idx <= mid) {
			update_seg_tree(idx, val, l, mid, 2 * pos + 1);	
		} else {
			update_seg_tree(idx, val, mid + 1, r, 2 * pos + 2);	
		}

		underlying[pos] = min(underlying[2 * pos + 1], underlying[2 * pos + 2]);
    }

    // Helpers
    static int get_size(int v) {
        v--;
        v |= v >> 1;
        v |= v >> 2;
        v |= v >> 4;
        v |= v >> 8;
        v |= v >> 16;
        v++;

        return (v * 2) - 1;
    }

    friend ostream& operator<<(ostream& os, const seg_tree<T>& st);
};

// Debug print
template <class T>
ostream& operator<<(ostream& os, const seg_tree<T>& st) {
    int level = 1;
    int count = 0;

    for (int i = 0; i < st.underlying.size(); ++i) {
        os << st.underlying[i] << " ";
        count++;

        if (count == level) {
            os << "\n";
            level <<= 1;
            count = 0;
        }
    }
    return os;
}

int main() {
    vector<int> v = {-1, 2, 4, 0};
    seg_tree<int> sg(v);

    cout << format("Between indicies 1 and 3 : {}\n", sg.query(1, 3));
	sg.update(3, 5);
    cout << format("Between indicies 1 and 3 : {}\n", sg.query(1, 3));
	

	

    // Basic tests to prove it works :)
}
