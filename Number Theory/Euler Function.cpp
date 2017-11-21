//欧拉函数递推求解

const int maxn = 100005;
int phi[maxn];

void init() {
    memset(phi, 0, sizeof(phi));
    phi[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (phi[i] == 0) {
            for (int j = i; j < maxn; j += i) {
                if (phi[j] == 0) phi[j] = j;
                phi[j] = (phi[j] / i) * (i - 1);
            }
        }
    }
}

//欧拉函数单个求解

long long ph(long long n) {
    long long ans = n, a = n;
    for (long long i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            ans = ans / i * (i - 1);
            while (a % i == 0) a /= i;
        }
    }
    if (a > 1) {
        ans = ans / a * (a - 1);
    }
    return ans;
}
