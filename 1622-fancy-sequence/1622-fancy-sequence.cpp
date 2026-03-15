class Fancy {
public:
    vector<long long> seq;
    long long mul;
    long long ad;
    const int mod = 1e9 + 7;
    vector<tuple<char, long long, int>> op;
    Fancy() {
        mul = 1;
        ad = 0;
    }

    void append(int val) { seq.push_back(val); }

    void addAll(int inc) {
        int n = op.size();
        if (n > 0) {
            auto &[ch, i, id] = op[n - 1];
            if (id == seq.size() - 1&&ch=='a') {
                i = (i + inc) % mod;
            } else {
                op.push_back({'a', inc, seq.size() - 1});
            }
        } else {
            op.push_back({'a', inc, seq.size() - 1});
        }
    }

    void multAll(int m) {
        int n = op.size();
        if (n > 0) {
            auto &[ch, i, id] = op[n - 1];
            if (id == seq.size() - 1&&ch=='m') {
                i = (i * m) % mod;
            } else {
                op.push_back({'m', m, seq.size() - 1});
            }
        } else {
            op.push_back({'m', m, seq.size() - 1});
        }
    }

    int getIndex(int idx) {
        if (idx >= seq.size())
            return -1;
        long long ans = seq[idx];
        for (auto [ch, i, id] : op) {
            if (id >= idx) {
                if (ch == 'a') {
                    ans = (ans + i) % mod;
                } else {
                    ans = (ans * i) % mod;
                }
            }
        }
        return ans;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */