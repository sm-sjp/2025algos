#include <iostream>
#include <tuple>
using namespace std;
#define ll long long
#define MOD 1000000007

// 페르마 소정리
ll mod_pow(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll k, n;
    cin >> k >> n;
    ll t = 1;
    for (int i = 0; i <= k; i++) {  // 시간초과 유의
        t = t * (n + i) % MOD;
    }
    ll d = 1;
    for (int i = k + 1; i >= 1; i--) {  // 시간초과 유의
        d = (d * i) % MOD;
    }

    ll x = mod_pow(d, MOD - 2);
    x %= MOD;
    cout << (t % MOD * x % MOD) % MOD << "\n";

    return 0;
}
