#include <algorithm>
#include <iostream>
using namespace std;

int N, K;
int a, b;
int tree[(1 << 18)];

int init(int node, int s, int e) {
    if (s == e) return tree[node] = 1;
    int mid = (s + e) / 2;
    return tree[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
}
int update(int node, int s, int e, int idx) {
    tree[node]--;
    if (s == e)
        return 0;
    else {
        int mid = (s + e) / 2;
        if (idx <= mid)
            return update(2 * node, s, mid, idx);
        else
            return update(2 * node + 1, mid + 1, e, idx);
    }
}
int query(int node, int s, int e, int order) {
    if (s == e) return s;
    int mid = (s + e) / 2;
    if (order <= tree[2 * node])
        return query(2 * node, s, mid, order);
    else
        return query(2 * node + 1, mid + 1, e, order - tree[2 * node]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    init(1, 1, N);
    int idx = 1;
    cout << "<";
    for (int i = 0; i < N; i++) {
        int people = N - i;
        idx += K - 1;
        if (idx % people == 0)
            idx = people;
        else if (idx > people)
            idx %= people;
        int n = query(1, 1, N, idx);
        update(1, 1, N, n);
        if (i == N - 1)
            cout << n;
        else
            cout << n << ", ";
    }
    cout << ">";

    return 0;
}
