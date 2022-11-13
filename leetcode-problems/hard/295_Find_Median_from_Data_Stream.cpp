class MedianFinder {
public:

    int base = 100000;
    int maxValue = 200000;
    vector<int> bit;
    int size = 0;

    int query(int r)
    {
        int res = 0;
        for ( ; r >= 0; r = (r & (r + 1)) - 1) {
            res += bit[r];
        }
        return res;
    }

    void add(int idx, int delta)
    {
        for ( ; idx <= maxValue; idx = idx | (idx + 1)) {
            bit[idx] += delta;
        }
    }

    MedianFinder() {
        bit = vector<int>(maxValue + 1, 0);
    }
    
    void addNum(int num) {
        size++;
        add(base + num, +1);
    }
    
    int findAtAPosition(int pos) {
        int lo = 0;
        int hi = maxValue;
        int ans = INT_MAX;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int d = query(mid);
            if (d >= pos) {
                ans = min(ans, mid);
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        return ans - base;
    }

    double findMedian() {
        if (size % 2) {
            return findAtAPosition(size / 2 + 1);
        }
        else {
            return (findAtAPosition(size / 2) + findAtAPosition(size / 2 + 1)) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */