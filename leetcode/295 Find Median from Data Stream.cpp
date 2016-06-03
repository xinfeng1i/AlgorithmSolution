// Use big-heap and small-heap to peek medium
// Note that the numbers that are pushed may has duplicates
// thus should use "MULTISET" instead of "SET"
class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int x) {
        if (s2.empty()) {
            s1.insert(x);
            if (s1.size() - s2.size() >= 2) {
                int temp = *s1.begin();
                s1.erase(s1.begin());
                s2.insert(temp);
            }
        } else {
            int t2 = *s2.begin();
            if (x <= t2) {
                s1.insert(x);
                if (s1.size() - s2.size() >= 2) {
                    int temp = *s1.begin();
                    s1.erase(s1.begin());
                    s2.insert(temp);
                }
            } else {
                s2.insert(x);
                if (s2.size() - s1.size() >= 2) {
                    int temp = *s2.begin();
                    s2.erase(s2.begin());
                    s1.insert(temp);
                }
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        double ans = 0.0;
        if (s1.size() == s2.size()) {
            if (s1.empty()) return ans;
            int temp1 = *s1.begin();
            int temp2 = *s2.begin();
            ans = (temp1 + temp2) / 2.0;
        } else if(s1.size() == s2.size() + 1) {
            ans = double(*s1.begin());
        } else if(s1.size() + 1 == s2.size()) {
            ans = double(*s2.begin());
        }
        return ans;
    }
private:
    multiset<int, greater<int>> s1; // big root heap on the right
    multiset<int> s2; // small root heap on the right
};
