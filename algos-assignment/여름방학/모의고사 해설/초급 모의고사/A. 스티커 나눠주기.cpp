#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int T, B;
    int maxT = 0;
    int minB = 5000;
    for (int i = 0; i < N; i++) {
        cin >> T >> B;
        if (T > maxT) maxT = T;
        if (B < minB) minB = B;
    }
    cout << (maxT * minB) % 7 + 1;

    return 0;
}
