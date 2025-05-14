#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> arr, tree;

long long init(int start, int end, int node) {
    if (start == end) {
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right) {
    if (right < start || end < left) return 0;

    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int idx, long long diff) {
    if (idx < start || idx > end) return;

    tree[node] += diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx, diff);
        update(mid + 1, end, node * 2 + 1, idx, diff);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    arr.resize(N + 1);
    tree.resize(N * 4);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    init(1, N, 1);

    for (int i = 0; i < M + K; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        if (a == 1) {
            long long diff = c - arr[b];
            arr[b] = c;
            update(1, N, 1, b, diff);
        } else if (a == 2) {
            cout << sum(1, N, 1, b, (int)c) << '\n';
        }
    }

    return 0;
}
