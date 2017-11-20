const int maxn = ;
int n;
int sum[maxn];

void init() {
    memset(sum, 0, sizeof(sum));
}

inline int lowbit(int p) {
    return p & (-p);
}

void update(int p, int v) {
    while (p > 0) {
        sum[p] += v;
        p -= lowbit(p);
    }
}

int query(int p) {
    int res = 0;
    while (p <= n) {
        res += sum[p];
        p += lowbit(p);
    }
    return res;
}
